%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "exprtree.h"

int yylex(void);
void yyerror(char const *s);
FILE *target_file;
extern FILE *yyin;

int current_type; 
int current_func_type; 
extern struct TupleDefNode *current_tuple_type; /* NEW: Tracks tuple schema being parsed */
%}

%union {
    int val;
    char *varname;
    struct tnode *no;
    struct ParamNode *param; 
    struct FieldNode *FieldNode_ptr; /* NEW: Added to support tuple field lists */
}

%token INT STR MAIN RETURN TUPLE DOT /* NEW: Tuple Tokens */
%token DECL ENDDECL 
%token BEGIN_TOK END_TOK READ WRITE ASSIGN
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE
%token LT GT LE GE EQ NE
%token REPEAT UNTIL CONTINUE BREAK
%token AND
%token PLUS MINUS MUL DIV

%token <val> NUM
%token <varname> ID STRING
%type <no> slist stmt expr Body ArgList 
%type <param> ParamList Param            
%type <varname> FuncName
%type <FieldNode_ptr> FieldDefList FieldDef /* NEW: Tuple Field Types */

%nonassoc LT GT LE GE EQ NE
%left AND
%left PLUS MINUS
%left MUL DIV
%right '&'
%right USTAR
%left DOT  /* NEW: High precedence for field access */

%%
Program : GDeclBlock FDefBlock MainBlock 
        | GDeclBlock MainBlock 
        | MainBlock 
        ;

/* ========================================== */
/* 1. Global Declarations                     */
/* ========================================== */
GDeclBlock : DECL GDeclList ENDDECL | DECL ENDDECL ;
GDeclList  : GDeclList GDecl | GDecl ;

GDecl      : Type GVarList ';' 
           /* NEW: Tuple Global Declaration Block */
           | TUPLE ID '(' FieldDefList ')' { 
                current_tuple_type = TupleInstall($2, $4); 
             } TupGVarList ';' 
           ;

Type       : INT { current_type = TYPE_INT; }
           | STR { current_type = TYPE_STR; }
           ;

/* NEW: Standard Global Variables (Now passing NULL for tuptype) */
GVarList   : GVarList ',' GVar | GVar ;
GVar       : ID                      { GInstall($1, current_type, 1, NULL, NULL); }
           | ID '[' NUM ']'          { GInstall($1, current_type, $3, NULL, NULL); }
           | ID '(' ParamList ')'    { GInstall($1, current_type, 0, $3, NULL); } 
           | MUL ID                  { GInstall($2, (current_type == TYPE_INT) ? TYPE_INTPTR : TYPE_STRPTR, 1, NULL, NULL); }
           | MUL ID '(' ParamList ')'{ GInstall($2, (current_type == TYPE_INT) ? TYPE_INTPTR : TYPE_STRPTR, 0, $4, NULL); }
           ;

/* NEW: Tuple Global Variables */
TupGVarList : TupGVarList ',' ID     { GInstall($3, TYPE_TUPLE, 1, NULL, current_tuple_type); }
            | TupGVarList ',' MUL ID { GInstall($4, TYPE_TUPLE, 1, NULL, current_tuple_type); }
            | ID                     { GInstall($1, TYPE_TUPLE, 1, NULL, current_tuple_type); }
            | MUL ID                 { GInstall($2, TYPE_TUPLE, 1, NULL, current_tuple_type); }
            ;

/* NEW: Field Definitions for Tuple Schemas */
FieldDefList: FieldDefList ',' FieldDef {
                struct FieldNode *temp = $1;
                while(temp->next != NULL) temp = temp->next;
                temp->next = $3;
                $$ = $1;
            }
            | FieldDef { $$ = $1; }
            ;

FieldDef    : Type ID {
                struct FieldNode *f = (struct FieldNode *)malloc(sizeof(struct FieldNode));
                f->name = $2;
                f->type = current_type;
                f->next = NULL;
                $$ = f;
            }
            ;

ParamList  : ParamList ',' Param {
                struct ParamNode *temp = $1;
                while(temp->next != NULL) temp = temp->next;
                temp->next = $3;
                $$ = $1;
           }
           | Param { $$ = $1; }
           | /* Empty */ { $$ = NULL; }
           ;

Param      : Type ID {
                struct ParamNode *temp = (struct ParamNode *)malloc(sizeof(struct ParamNode));
                temp->name = $2;
                temp->type = current_type;
                temp->next = NULL;
                $$ = temp;
           }
           | Type MUL ID {
                struct ParamNode *temp = (struct ParamNode *)malloc(sizeof(struct ParamNode));
                temp->name = $3;
                temp->type = (current_type == TYPE_INT) ? TYPE_INTPTR : TYPE_STRPTR;
                temp->next = NULL;
                $$ = temp;
           }
           ;

/* ========================================== */
/* 2. Function Definitions                    */
/* ========================================== */
FDefBlock  : FDefBlock FDef | FDef ;

FuncName   : ID { 
                current_func_type = current_type; 
                $$ = $1; 
           }
           | MUL ID { 
                current_func_type = (current_type == TYPE_INT) ? TYPE_INTPTR : TYPE_STRPTR; 
                $$ = $2; 
           }
           ;

FDef       : Type FuncName '(' ParamList ')' '{' LDeclBlock {
                /* MID-RULE ACTION: Execute this BEFORE parsing Body */
                struct GST_Node *g = GLookup($2);
                if (g == NULL) { 
                    printf("Semantic Error: Function '%s' not declared.\n", $2); 
                    exit(1); 
                }

                if (g->type != current_func_type) {
                    printf("Semantic Error: Return type mismatch for function '%s'.\n", $2);
                    exit(1);
                }
                
                struct ParamNode *decl_param = g->paramlist; 
                struct ParamNode *def_param = $4;            
                
                while (decl_param != NULL && def_param != NULL) {
                    if (strcmp(decl_param->name, def_param->name) != 0) {
                        printf("Semantic Error: Parameter name mismatch in '%s'. Expected '%s', got '%s'.\n", 
                               $2, decl_param->name, def_param->name);
                        exit(1);
                    }
                    if (decl_param->type != def_param->type) {
                        printf("Semantic Error: Parameter type mismatch in '%s' for '%s'.\n", 
                               $2, decl_param->name);
                        exit(1);
                    }
                    decl_param = decl_param->next;
                    def_param = def_param->next;
                }
                
                if (decl_param != NULL || def_param != NULL) {
                    printf("Semantic Error: Parameter count in definition of '%s' does not match declaration.\n", $2);
                    exit(1);
                }

                InstallParameters($4);
                
           } Body '}' {
                /* END-RULE ACTION: Execute this AFTER parsing Body */
                struct GST_Node *g = GLookup($2);
                
                fprintf(target_file, "F%d:\n", g->flabel);
                fprintf(target_file, "PUSH BP\n");
                fprintf(target_file, "MOV BP, SP\n");
                
                int num_locals = local_binding - 1;
                for(int i = 0; i < num_locals; i++) {
                    fprintf(target_file, "PUSH R0\n");
                }
                
                if ($9 != NULL) codeGen($9);
                
                LST_reset(); 
           }
           ;

/* --- Local Declarations --- */
LDeclBlock : DECL LDeclList ENDDECL | DECL ENDDECL | /* Empty */ ;
LDeclList  : LDeclList LDecl | LDecl ;

LDecl      : Type LVarList ';' 
           /* NEW: Tuple Local Declaration Block */
           | TUPLE ID '(' FieldDefList ')' { 
                current_tuple_type = TupleInstall($2, $4); 
             } TupLVarList ';' 
           ;

/* NEW: Standard Local Variables (Passing NULL for tuptype) */
LVarList   : LVarList ',' ID         { LInstall($3, current_type, local_binding++, NULL); }
           | ID                      { LInstall($1, current_type, local_binding++, NULL); }
           | LVarList ',' MUL ID     { LInstall($4, (current_type == TYPE_INT) ? TYPE_INTPTR : TYPE_STRPTR, local_binding++, NULL); }
           | MUL ID                  { LInstall($2, (current_type == TYPE_INT) ? TYPE_INTPTR : TYPE_STRPTR, local_binding++, NULL); }
           ;

/* NEW: Tuple Local Variables (Reserving space for all fields) */
TupLVarList : TupLVarList ',' ID { 
                LInstall($3, TYPE_TUPLE, local_binding, current_tuple_type); 
                local_binding += current_tuple_type->size; 
            }
            | ID { 
                LInstall($1, TYPE_TUPLE, local_binding, current_tuple_type); 
                local_binding += current_tuple_type->size; 
            }
            ;

/* ========================================== */
/* 3. Main Block & Body                       */
/* ========================================== */
MainBlock  : INT MAIN '(' ')' '{' LDeclBlock {
                current_func_type = TYPE_INT; 
           } Body '}' {
           
                fprintf(target_file, "MAIN:\n");
                fprintf(target_file, "PUSH BP\n");
                fprintf(target_file, "MOV BP, SP\n");
                
                int num_locals = local_binding - 1;
                for(int i = 0; i < num_locals; i++) {
                    fprintf(target_file, "PUSH R0\n");
                }

                if ($8 != NULL) codeGen($8);

                LST_reset();
           }
           ;

Body       : BEGIN_TOK slist END_TOK { $$ = $2; }
           | BEGIN_TOK END_TOK       { $$ = NULL; }
           ;

slist : slist stmt { $$ = createTree(0, TYPE_VOID, NULL, NODE_CONN, $1, $2); }
      | stmt       { $$ = $1; }
      ;

stmt : READ '(' MUL expr ')' ';' { 
            struct tnode *ptrNode = createTree(0, TYPE_INT, NULL, NODE_PTR_DEREF, $4, NULL);
            $$ = createTree(0, TYPE_VOID, NULL, NODE_READ, ptrNode, NULL); 
       }
     /* NEW: Read into Tuple Field */
     | READ '(' expr DOT ID ')' ';' {
            if ($3->type != TYPE_TUPLE) {
                printf("Semantic Error: Left of '.' is not a tuple.\n"); exit(1);
            }
            struct FieldNode *f = GetField($3->tuptype, $5);
            if (!f) {
                printf("Semantic Error: Field '%s' does not exist.\n", $5); exit(1);
            }
            struct tnode *fieldNode = createTree(f->offset, f->type, NULL, NODE_FIELD, $3, NULL);
            $$ = createTree(0, TYPE_VOID, NULL, NODE_READ, fieldNode, NULL);
       }
     | MUL expr ASSIGN expr ';' { 
            struct tnode *ptrNode = createTree(0, TYPE_INT, NULL, NODE_PTR_DEREF, $2, NULL);
            $$ = createTree(0, TYPE_VOID, NULL, NODE_ASSIGN, ptrNode, $4); 
       }
     | READ '(' ID '[' expr ']' '[' expr ']' ')' ';' { 
            struct tnode *varNode = createTree(0, 0, $3, NODE_VAR, NULL, NULL);
            struct tnode *idxNode = createTree(0, TYPE_INT, NULL, NODE_INDEX, $5, $8); 
            struct tnode *arrNode = createTree(0, TYPE_INT, NULL, NODE_ARRAY_2D, varNode, idxNode);
            $$ = createTree(0, TYPE_VOID, NULL, NODE_READ, arrNode, NULL); 
       }
     | ID '[' expr ']' '[' expr ']' ASSIGN expr ';' { 
            struct tnode *varNode = createTree(0, 0, $1, NODE_VAR, NULL, NULL);
            struct tnode *idxNode = createTree(0, TYPE_INT, NULL, NODE_INDEX, $3, $6);
            struct tnode *arrNode = createTree(0, TYPE_INT, NULL, NODE_ARRAY_2D, varNode, idxNode);
            $$ = createTree(0, TYPE_VOID, NULL, NODE_ASSIGN, arrNode, $9); 
       }
     | READ '(' ID ')' ';' { 
            struct tnode *varNode = createTree(0, 0, $3, NODE_VAR, NULL, NULL);
            $$ = createTree(0, TYPE_VOID, NULL, NODE_READ, varNode, NULL); 
       }
     | READ '(' ID '[' expr ']' ')' ';' { 
            struct tnode *varNode = createTree(0, 0, $3, NODE_VAR, NULL, NULL);
            struct tnode *arrNode = createTree(0, TYPE_INT, NULL, NODE_ARRAY, varNode, $5);
            $$ = createTree(0, TYPE_VOID, NULL, NODE_READ, arrNode, NULL); 
       }
     | WRITE '(' expr ')' ';' { $$ = createTree(0, TYPE_VOID, NULL, NODE_WRITE, $3, NULL); }
     
     /* Tuple-to-Tuple and Standard Assignments */
     | ID ASSIGN expr ';' { 
            struct tnode *varNode = createTree(0, 0, $1, NODE_VAR, NULL, NULL);
            $$ = createTree(0, TYPE_VOID, NULL, NODE_ASSIGN, varNode, $3); 
       }
       
     /* NEW: Assign to Tuple Field (e.g. a.name = "John") */
     | expr DOT ID ASSIGN expr ';' {
            if ($1->type != TYPE_TUPLE) {
                printf("Semantic Error: Left of '.' is not a tuple.\n"); exit(1);
            }
            struct FieldNode *f = GetField($1->tuptype, $3);
            if (!f) {
                printf("Semantic Error: Field '%s' does not exist.\n", $3); exit(1);
            }
            struct tnode *fieldNode = createTree(f->offset, f->type, NULL, NODE_FIELD, $1, NULL);
            $$ = createTree(0, TYPE_VOID, NULL, NODE_ASSIGN, fieldNode, $5);
       }
       
     | ID '[' expr ']' ASSIGN expr ';' { 
            struct tnode *varNode = createTree(0, 0, $1, NODE_VAR, NULL, NULL);
            struct tnode *arrNode = createTree(0, TYPE_INT, NULL, NODE_ARRAY, varNode, $3);
            $$ = createTree(0, TYPE_VOID, NULL, NODE_ASSIGN, arrNode, $6); 
       }
     | IF '(' expr ')' THEN slist ELSE slist ENDIF ';' { 
            struct tnode *then_else = createTree(0, TYPE_VOID, NULL, NODE_CONN, $6, $8);
            $$ = createTree(0, TYPE_VOID, NULL, NODE_IF_ELSE, $3, then_else); 
       }
     | IF '(' expr ')' THEN slist ENDIF ';'          { $$ = createTree(0, TYPE_VOID, NULL, NODE_IF, $3, $6); }
     | WHILE '(' expr ')' DO slist ENDWHILE ';'      { $$ = createTree(0, TYPE_VOID, NULL, NODE_WHILE, $3, $6); }
     | DO slist WHILE '(' expr ')' ';'               { $$ = createTree(0, TYPE_VOID, NULL, NODE_DO_WHILE, $5, $2); }     
     | REPEAT slist UNTIL '(' expr ')' ';'           { $$ = createTree(0, TYPE_VOID, NULL, NODE_REPEAT_UNTIL, $5, $2); } 
     | BREAK ';'                                     { $$ = createTree(0, TYPE_VOID, NULL, NODE_BREAK, NULL, NULL); }
     | CONTINUE ';'                                  { $$ = createTree(0, TYPE_VOID, NULL, NODE_CONTINUE, NULL, NULL); }
     
     | RETURN expr ';' {
            if ($2->type != current_func_type) {
                printf("Semantic Error: Return type mismatch. Expected %d, got %d.\n", current_func_type, $2->type);
                exit(1);
            }
            $$ = createTree(0, TYPE_VOID, NULL, NODE_RET, $2, NULL);
       }
     ;

ArgList : ArgList ',' expr {
            struct tnode *temp = $1;
            while(temp->right != NULL) temp = temp->right;
            temp->right = createTree(0, TYPE_VOID, NULL, NODE_CONN, $3, NULL);
            $$ = $1;
        }
        | expr             { $$ = createTree(0, TYPE_VOID, NULL, NODE_CONN, $1, NULL); }
        | /* Empty */      { $$ = NULL; }
        ;

expr : MUL expr %prec USTAR { 
            int base_type = ($2->type == TYPE_INTPTR) ? TYPE_INT : TYPE_STR;
            $$ = createTree(0, base_type, NULL, NODE_PTR_DEREF, $2, NULL); 
       }
     | '&' ID { 
            struct tnode *varNode = createTree(0, 0, $2, NODE_VAR, NULL, NULL);
            int ptr_type = (varNode->type == TYPE_INT) ? TYPE_INTPTR : TYPE_STRPTR;
            $$ = createTree(0, ptr_type, NULL, NODE_PTR_ADDR, varNode, NULL); 
       }
     | ID '[' expr ']' '[' expr ']' { 
            struct tnode *varNode = createTree(0, 0, $1, NODE_VAR, NULL, NULL);
            struct tnode *idxNode = createTree(0, TYPE_INT, NULL, NODE_INDEX, $3, $6);
            $$ = createTree(0, varNode->type, NULL, NODE_ARRAY_2D, varNode, idxNode); 
       }
       
     /* NEW: Extract Tuple Field (e.g. y = a.name) */
     | expr DOT ID {
            if ($1->type != TYPE_TUPLE) {
                printf("Semantic Error: Left of '.' is not a tuple.\n"); exit(1);
            }
            struct FieldNode *f = GetField($1->tuptype, $3);
            if (!f) {
                printf("Semantic Error: Field '%s' does not exist.\n", $3); exit(1);
            }
            $$ = createTree(f->offset, f->type, NULL, NODE_FIELD, $1, NULL);
       }
       
     | ID '(' ArgList ')' {
            struct GST_Node *g = GLookup($1);
            if (g == NULL) { 
                printf("Semantic Error: Function '%s' is not declared.\n", $1); 
                exit(1); 
            }
            
            struct ParamNode *param = g->paramlist;
            struct tnode *arg = $3;
            while (param != NULL && arg != NULL) {
                if (param->type != arg->left->type) { 
                    printf("Semantic Error: Argument type mismatch in call to '%s'.\n", $1);
                    exit(1);
                }
                param = param->next;
                arg = arg->right; 
            }
            if (param != NULL || arg != NULL) {
                printf("Semantic Error: Incorrect number of arguments passed to '%s'.\n", $1);
                exit(1);
            }

            struct tnode *funcNode = createTree(0, 0, $1, NODE_VAR, NULL, NULL);
            funcNode->Gentry = g; 
            $$ = createTree(0, g->type, NULL, NODE_FUNC_CALL, funcNode, $3); 
       }
       
     | expr PLUS expr   { $$ = createTree('+', TYPE_INT, NULL, NODE_OP, $1, $3); }
     | expr MINUS expr  { $$ = createTree('-', TYPE_INT, NULL, NODE_OP, $1, $3); }
     | expr MUL expr    { $$ = createTree('*', TYPE_INT, NULL, NODE_OP, $1, $3); }
     | expr DIV expr    { $$ = createTree('/', TYPE_INT, NULL, NODE_OP, $1, $3); }
     | expr LT expr     { $$ = createTree(LT, TYPE_BOOL, NULL, NODE_RELOP, $1, $3); }
     | expr GT expr     { $$ = createTree(GT, TYPE_BOOL, NULL, NODE_RELOP, $1, $3); }
     | expr LE expr     { $$ = createTree(LE, TYPE_BOOL, NULL, NODE_RELOP, $1, $3); }
     | expr GE expr     { $$ = createTree(GE, TYPE_BOOL, NULL, NODE_RELOP, $1, $3); }
     | expr EQ expr     { $$ = createTree(EQ, TYPE_BOOL, NULL, NODE_RELOP, $1, $3); }
     | expr NE expr     { $$ = createTree(NE, TYPE_BOOL, NULL, NODE_RELOP, $1, $3); }
     | expr AND expr    { $$ = createTree(AND, TYPE_BOOL, NULL, NODE_RELOP, $1, $3); }
     | '(' expr ')'     { $$ = $2; }
     | NUM              { $$ = createTree($1, TYPE_INT, NULL, NODE_NUM, NULL, NULL); }
     | STRING           { $$ = createTree(0, TYPE_STR, $1, NODE_STR_VAL, NULL, NULL); }
     | ID               { $$ = createTree(0, 0, $1, NODE_VAR, NULL, NULL); } /* type/tuptype loaded in createTree */
     | ID '[' expr ']'  { 
            struct tnode *varNode = createTree(0, 0, $1, NODE_VAR, NULL, NULL);
            $$ = createTree(0, varNode->type, NULL, NODE_ARRAY, varNode, $3); 
       }
     ;
%%

void yyerror(char const *s) { 
    extern char *yytext;
    printf("YYError: %s at token '%s'\n", s, yytext); 
}
void makeBootCode() {
    fprintf(target_file, "BOOT:\n");
    fprintf(target_file, "MOV SP, %d\n", getSP());
    fprintf(target_file, "PUSH R0\n"); /* Space for MAIN's return value */
    fprintf(target_file, "CALL MAIN\n");
    
    /* Safely Halt the Machine via Exit */
    int r = getReg();
    fprintf(target_file, "MOV R%d, \"Exit\"\n", r);
    fprintf(target_file, "PUSH R%d\n", r);      
    fprintf(target_file, "MOV R%d, 0\n", r);
    fprintf(target_file, "PUSH R%d\n", r);      
    fprintf(target_file, "PUSH R%d\n", r);      
    fprintf(target_file, "PUSH R%d\n", r);     
    fprintf(target_file, "PUSH R%d\n", r);      
    fprintf(target_file, "CALL 0\n");
    freeReg();
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (fp) yyin = fp;
        else { printf("Error opening input file: %s\n", argv[1]); return 1; }
    }
    target_file = fopen("target.xsm", "w");
    if (!target_file) { printf("Error creating target.xsm\n"); return 1; }
    
    /* XSM Header & Boot Sequence */
    fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(target_file, "JMP BOOT\n"); 
    
    yyparse();
    makeBootCode();
    return 0;
}