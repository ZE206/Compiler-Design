%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "exprtree.h"

int yylex(void);
void yyerror(char const *s);
FILE *target_file;
extern FILE *yyin;

struct Typetable *current_type = NULL;
struct Typetable *current_func_type = NULL;
static struct Typetable *curr_type_defining = NULL;

void makeBootCode(void);
%}

%union {
    int val;
    char *varname;
    struct Typetable *type;
    struct tnode *no;
    struct ParamNode *param;
}

%token INT STR MAIN RETURN
%token TYPE ENDTYPE DECL ENDDECL 
%token BEGIN_TOK END_TOK READ WRITE ASSIGN
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE
%token LT GT LE GE EQ NE
%token REPEAT UNTIL CONTINUE BREAK
%token AND
%token INIT ALLOC FREE NULL_TOK DOT
%token PLUS MINUS MUL DIV

%token <val> NUM
%token <varname> ID STRING
%type <type> TypeName
%type <no> slist stmt expr Body ArgList Field
%type <param> ParamList Param
%type <varname> FuncName

%nonassoc LT GT LE GE EQ NE
%left AND
%left PLUS MINUS
%left MUL DIV
%right '&'
%right USTAR
%left DOT

%%
Program : TypeDefBlock GDeclBlock FDefBlock MainBlock 
        | TypeDefBlock GDeclBlock MainBlock 
        | TypeDefBlock MainBlock 
        ;

/* ========================================== */
/* Type Definitions (UDTs)                    */
/* ========================================== */

TypeDefBlock : TYPE TypeDefList ENDTYPE
             | TYPE ENDTYPE
             | /* Empty */
             ;

TypeDefList  : TypeDefList TypeDef
             | TypeDef
             ;

TypeDef      : ID '{' {
                /* Pre-install shell to allow recursive structures (e.g. node.next) */
                curr_type_defining = TInstall($1, 0, NULL);
             } FieldDeclList '}' {
                curr_type_defining = NULL;
             }
             ;

FieldDeclList : FieldDeclList FieldDecl
              | FieldDecl
              ;

FieldDecl     : TypeName ID ';' {
                FInstall(curr_type_defining, $2, $1->name);
              }
              ;

TypeName      : INT  { $$ = TLookup("int"); }
              | STR  { $$ = TLookup("str"); }
              | ID   { 
                  struct Typetable *t = TLookup($1);
                  if (!t) {
                      printf("Semantic Error: Unknown type '%s'.\n", $1);
                      exit(1);
                  }
                  $$ = t;
              }
              ;

/* ========================================== */
/* Global Declarations                        */
/* ========================================== */

GDeclBlock : DECL GDeclList ENDDECL | DECL ENDDECL ;
GDeclList  : GDeclList GDecl | GDecl ;
GDecl      : TypeName { current_type = $1; } GVarList ';' ;

GVarList   : GVarList ',' GVar | GVar ;
GVar       : ID                      { GInstall($1, current_type, 1, NULL); }
           | ID '[' NUM ']'          { GInstall($1, current_type, $3, NULL); }
           | ID '(' ParamList ')'    { GInstall($1, current_type, 0, $3); } 
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

Param      : TypeName ID {
                struct ParamNode *temp = (struct ParamNode *)malloc(sizeof(struct ParamNode));
                temp->name = $2;
                temp->type = $1;
                temp->next = NULL;
                $$ = temp;
           }
           ;

/* ========================================== */
/* Function Definitions                       */
/* ========================================== */

FDefBlock  : FDefBlock FDef | FDef ;

FuncName   : ID { 
                current_func_type = current_type; 
                $$ = $1; 
           }
           ;

FDef       : TypeName FuncName '(' ParamList ')' '{' LDeclBlock {
                struct GST_Node *g = GLookup($2);
                if (g == NULL) { 
                    printf("Semantic Error: Function '%s' not declared.\n", $2); 
                    exit(1); 
                }
                if (g->type != $1) {
                    printf("Semantic Error: Return type mismatch for function '%s'.\n", $2);
                    exit(1);
                }
                current_func_type = g->type; 

                /* Formal parameter verification */
                struct ParamNode *decl_p = g->paramlist;
                struct ParamNode *def_p = $4;
                while (decl_p && def_p) {
                    if (strcmp(decl_p->name, def_p->name) != 0 || decl_p->type != def_p->type) {
                        printf("Semantic Error: Formal parameters do not match signature in '%s'.\n", $2);
                        exit(1);
                    }
                    decl_p = decl_p->next;
                    def_p = def_p->next;
                }
                if (decl_p != NULL || def_p != NULL) {
                    printf("Semantic Error: Parameter count mismatch in '%s'.\n", $2);
                    exit(1);
                }

                InstallParameters($4);
           } Body '}' {
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
LDecl      : TypeName { current_type = $1; } LVarList ';' ;
LVarList   : LVarList ',' ID { LInstall($3, current_type, local_binding++); }
           | ID              { LInstall($1, current_type, local_binding++); }
           ;

/* ========================================== */
/* Main Block                                 */
/* ========================================== */

MainBlock  : INT MAIN '(' ')' '{' LDeclBlock {
                current_func_type = TLookup("int"); 
           } Body '}' {
                fprintf(target_file, "MAIN:\n");
                fprintf(target_file, "PUSH BP\n");
                fprintf(target_file, "MOV BP, SP\n");
                
                int num_locals = local_binding - 1;
                for(int i = 0; i < num_locals; i++) {
                    fprintf(target_file, "PUSH R0\n");
                }

                if ($8 != NULL) codeGen($8);

                /* Graceful fallthrough cleanup in case return 0 was omitted */
                int discard = getReg();
                for(int i = 0; i < num_locals; i++) {
                    fprintf(target_file, "POP R%d\n", discard);
                }
                freeReg();
                fprintf(target_file, "POP BP\n");
                fprintf(target_file, "RET\n");

                LST_reset();
           }
           ;

Body       : BEGIN_TOK slist END_TOK { $$ = $2; }
           | BEGIN_TOK END_TOK       { $$ = NULL; }
           ;

slist : slist stmt { $$ = createTree(0, TLookup("void"), NULL, NODE_CONN, $1, $2); }
      | stmt       { $$ = $1; }
      ;

stmt : READ '(' ID ')' ';' { 
            struct tnode *v = createTree(0, NULL, $3, NODE_VAR, NULL, NULL);
            $$ = createTree(0, TLookup("void"), NULL, NODE_READ, v, NULL); 
       }
     | READ '(' Field ')' ';' {
            $$ = createTree(0, TLookup("void"), NULL, NODE_READ, $3, NULL);
     }
     | WRITE '(' expr ')' ';' { $$ = createTree(0, TLookup("void"), NULL, NODE_WRITE, $3, NULL); }
     | ID ASSIGN expr ';' { 
            struct tnode *v = createTree(0, NULL, $1, NODE_VAR, NULL, NULL);
            $$ = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, v, $3); 
       }
     | Field ASSIGN expr ';' {
            $$ = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, $1, $3);
     }
     | ID '[' expr ']' ASSIGN expr ';' { 
            struct tnode *varNode = createTree(0, NULL, $1, NODE_VAR, NULL, NULL);
            struct tnode *arrNode = createTree(0, varNode->type, NULL, NODE_ARRAY, varNode, $3);
            $$ = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, arrNode, $6); 
       }
     | FREE '(' ID ')' ';' {
            struct tnode *v = createTree(0, NULL, $3, NODE_VAR, NULL, NULL);
            $$ = createTree(0, TLookup("void"), NULL, NODE_FREE, v, NULL);
     }
     | FREE '(' Field ')' ';' {
            $$ = createTree(0, TLookup("void"), NULL, NODE_FREE, $3, NULL);
     }
     | IF '(' expr ')' THEN slist ELSE slist ENDIF ';' { 
            struct tnode *then_else = createTree(0, TLookup("void"), NULL, NODE_CONN, $6, $8);
            $$ = createTree(0, TLookup("void"), NULL, NODE_IF_ELSE, $3, then_else); 
       }
     | IF '(' expr ')' THEN slist ENDIF ';'          { $$ = createTree(0, TLookup("void"), NULL, NODE_IF, $3, $6); }
     | WHILE '(' expr ')' DO slist ENDWHILE ';'      { $$ = createTree(0, TLookup("void"), NULL, NODE_WHILE, $3, $6); }
     | DO slist WHILE '(' expr ')' ';'               { $$ = createTree(0, TLookup("void"), NULL, NODE_DO_WHILE, $5, $2); }     
     | REPEAT slist UNTIL '(' expr ')' ';'           { $$ = createTree(0, TLookup("void"), NULL, NODE_REPEAT_UNTIL, $5, $2); } 
     | BREAK ';'                                     { $$ = createTree(0, TLookup("void"), NULL, NODE_BREAK, NULL, NULL); }
     | CONTINUE ';'                                  { $$ = createTree(0, TLookup("void"), NULL, NODE_CONTINUE, NULL, NULL); }
     | RETURN expr ';' {
            int is_udt = (current_func_type != TLookup("int") && current_func_type != TLookup("str") && current_func_type != TLookup("boolean"));
            if ($2->type != current_func_type) {
                if (!(is_udt && $2->type == TLookup("null"))) {
                    printf("Semantic Error: Return type mismatch. Expected '%s', got '%s'.\n", 
                           current_func_type->name, $2->type ? $2->type->name : "null");
                    exit(1);
                }
            }
            $$ = createTree(0, TLookup("void"), NULL, NODE_RET, $2, NULL);
       }
     ;

/* Chained Field Resolution */
Field : ID DOT ID {
            struct tnode *v = createTree(0, NULL, $1, NODE_VAR, NULL, NULL);
            struct Fieldlist *f = FLookup(v->type, $3);
            if (!f) {
                printf("Semantic Error: Field '%s' does not exist in type '%s'.\n", $3, v->type ? v->type->name : "unknown");
                exit(1);
            }
            $$ = createTree(f->fieldIndex, f->type, $3, NODE_FIELD, v, NULL);
            $$->Fentry = f;
      }
      | Field DOT ID {
            struct Fieldlist *f = FLookup($1->type, $3);
            if (!f) {
                printf("Semantic Error: Field '%s' does not exist in type '%s'.\n", $3, $1->type ? $1->type->name : "unknown");
                exit(1);
            }
            $$ = createTree(f->fieldIndex, f->type, $3, NODE_FIELD, $1, NULL);
            $$->Fentry = f;
      }
      ;

ArgList : ArgList ',' expr {
            struct tnode *temp = $1;
            while(temp->right != NULL) temp = temp->right;
            temp->right = createTree(0, TLookup("void"), NULL, NODE_CONN, $3, NULL);
            $$ = $1;
        }
        | expr             { $$ = createTree(0, TLookup("void"), NULL, NODE_CONN, $1, NULL); }
        | /* Empty */      { $$ = NULL; }
        ;

expr : Field              { $$ = $1; }
     | INIT '(' ')'       { $$ = createTree(0, TLookup("int"), NULL, NODE_INIT, NULL, NULL); }
     | ALLOC '(' ')'      { $$ = createTree(0, TLookup("void"), NULL, NODE_ALLOC, NULL, NULL); }
     | NULL_TOK           { $$ = createTree(0, TLookup("null"), NULL, NODE_NULL, NULL, NULL); }
     | ID '(' ArgList ')' {
            struct GST_Node *g = GLookup($1);
            if (g == NULL) { 
                printf("Semantic Error: Function '%s' is not declared.\n", $1); 
                exit(1); 
            }
            struct ParamNode *param = g->paramlist;
            struct tnode *arg = $3;
            while (param != NULL && arg != NULL) {
                int p_is_udt = (param->type != TLookup("int") && 
                                param->type != TLookup("str") && 
                                param->type != TLookup("boolean"));

                if (param->type != arg->left->type) { 
                    /* Allow passing 'null' to any parameter expecting a UDT */
                    if (!(p_is_udt && arg->left->type == TLookup("null"))) {
                        printf("Semantic Error: Argument type mismatch in call to '%s'.\n", $1);
                        exit(1);
                    }
                }
                param = param->next;
                arg = arg->right; 
            }
            if (param != NULL || arg != NULL) {
                printf("Semantic Error: Incorrect argument count in '%s'.\n", $1);
                exit(1);
            }
            struct tnode *funcNode = createTree(0, NULL, $1, NODE_VAR, NULL, NULL);
            funcNode->Gentry = g; 
            $$ = createTree(0, g->type, NULL, NODE_FUNC_CALL, funcNode, $3); 
       }
     | expr PLUS expr   { $$ = createTree('+', TLookup("int"), NULL, NODE_OP, $1, $3); }
     | expr MINUS expr  { $$ = createTree('-', TLookup("int"), NULL, NODE_OP, $1, $3); }
     | expr MUL expr    { $$ = createTree('*', TLookup("int"), NULL, NODE_OP, $1, $3); }
     | expr DIV expr    { $$ = createTree('/', TLookup("int"), NULL, NODE_OP, $1, $3); }
     | expr LT expr     { $$ = createTree(LT, TLookup("boolean"), NULL, NODE_RELOP, $1, $3); }
     | expr GT expr     { $$ = createTree(GT, TLookup("boolean"), NULL, NODE_RELOP, $1, $3); }
     | expr LE expr     { $$ = createTree(LE, TLookup("boolean"), NULL, NODE_RELOP, $1, $3); }
     | expr GE expr     { $$ = createTree(GE, TLookup("boolean"), NULL, NODE_RELOP, $1, $3); }
     | expr EQ expr     { $$ = createTree(EQ, TLookup("boolean"), NULL, NODE_RELOP, $1, $3); }
     | expr NE expr     { $$ = createTree(NE, TLookup("boolean"), NULL, NODE_RELOP, $1, $3); }
     | expr AND expr    { $$ = createTree(AND, TLookup("boolean"), NULL, NODE_RELOP, $1, $3); }
     | '(' expr ')'     { $$ = $2; }
     | NUM              { $$ = createTree($1, TLookup("int"), NULL, NODE_NUM, NULL, NULL); }
     | STRING           { $$ = createTree(0, TLookup("str"), $1, NODE_STR_VAL, NULL, NULL); }
     | ID               { $$ = createTree(0, NULL, $1, NODE_VAR, NULL, NULL); }
     | ID '[' expr ']'  { 
            struct tnode *varNode = createTree(0, NULL, $1, NODE_VAR, NULL, NULL);
            $$ = createTree(0, varNode->type, NULL, NODE_ARRAY, varNode, $3); 
       }
     ;
%%

void yyerror(char const *s) { 
    extern char *yytext;
    printf("YYError: %s at token '%s'\n", s, yytext); 
}

void makeBootCode(void) {
    fprintf(target_file, "BOOT:\n");
    fprintf(target_file, "MOV SP, %d\n", getSP());
    fprintf(target_file, "PUSH R0\n");
    fprintf(target_file, "CALL MAIN\n");
    
    int r = getReg();
    fprintf(target_file, "MOV R%d, \"Exit\"\n", r);
    fprintf(target_file, "PUSH R%d\n", r);      
    fprintf(target_file, "MOV R%d, 0\n", r);
    fprintf(target_file, "PUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\n", r, r, r, r);
    fprintf(target_file, "CALL 0\n");
    freeReg();
}

int main(int argc, char *argv[]) {
    TypeTableCreate();

    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (fp) yyin = fp;
        else { printf("Error opening input file: %s\n", argv[1]); return 1; }
    }
    target_file = fopen("target.xsm", "w");
    if (!target_file) { printf("Error creating target.xsm\n"); return 1; }
    
    fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(target_file, "JMP BOOT\n"); 
    
    yyparse();
    makeBootCode();
    fclose(target_file);
    return 0;
}