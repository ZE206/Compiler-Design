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
struct Classtable *Cptr = NULL;

void makeBootCode(void);
extern struct Classtable *ClassTableHead;
void initializeVTables(struct Classtable *Chead);

int count_params(struct ParamNode *p) {
    int c = 0;
    while(p) { c++; p = p->next; }
    return c;
}
/* Helper 1: Mangles names during Method Declarations (using ParamList) */
char* mangleDecl(char* base, struct ParamNode* p) {
    char *buffer = (char*)malloc(256);
    strcpy(buffer, base);
    struct ParamNode *curr = p;
    while(curr != NULL) {
        strcat(buffer, "_");
        strcat(buffer, curr->type->name);
        curr = curr->next;
    }
    return buffer;
}

/* Helper 2: Mangles names during Method Calls (using ArgList AST nodes) */
char* mangleCall(char* base, struct tnode* args) {
    char *buffer = (char*)malloc(256);
    strcpy(buffer, base);
    struct tnode *curr = args;
    while(curr != NULL) {
        /* Extract the actual argument node from the CONN wrapper */
        struct tnode *argNode = curr;
        if (curr->nodetype == NODE_CONN) argNode = curr->left;
        
        strcat(buffer, "_");
        if (argNode->type != NULL) strcat(buffer, argNode->type->name);
        else strcat(buffer, "unknown");
        
        if (curr->nodetype == NODE_CONN) curr = curr->right;
        else curr = NULL;
    }
    return buffer;
}
%}

%union {
    int val;
    char *varname;
    struct Typetable *type;
    struct Classtable *ctype;
    struct tnode *no;
    struct ParamNode *param;
}

%token CLASS ENDCLASS NEW DELETE SELF EXTENDS
%type <ctype> Cname

%token INT STR MAIN RETURN
%token TYPE ENDTYPE DECL ENDDECL 
%token BEGIN_TOK END_TOK READ WRITE ASSIGN
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE
%token LT GT LE GE EQ NE
%token REPEAT UNTIL CONTINUE BREAK FOR
%token AND OR
%token INIT ALLOC FREE NULL_TOK DOT
%token PLUS MINUS MUL DIV MOD
%token SUPER
%token NOT TRUE FALSE INC DEC
%token SWITCH CASE DEFAULT
%token PLUS_EQ MINUS_EQ MUL_EQ DIV_EQ MOD_EQ

%token <val> NUM
%token <varname> ID STRING
%type <type> TypeName
%type <no> slist stmt expr Body ArgList Lvalue CaseList CaseStmt
%type <param> ParamList Param
%type <varname> FuncName

%right ASSIGN
%right NOT
%right '?' ':'
%left OR
%left AND
%nonassoc LT GT LE GE EQ NE
%left PLUS MINUS
%left MUL DIV MOD
%right '&'
%right USTAR
%left DOT

%%
/* SINGLE PROGRAM ENTRY POINT */
Program : TypeDefBlock ClassDefBlock GDeclBlock FDefList MainBlock
        ;

/* ========================================== */
/* Class Definitions                          */
/* ========================================== */

ClassDefBlock : CLASS ClassDefList ENDCLASS
              | /* Empty */
              ;

ClassDefList  : ClassDefList ClassDef
              | ClassDef
              ;

ClassDef      : Cname '{' DECL ClassDeclList ENDDECL MethodDefList '}' {
                    Cptr = NULL;
              }
              ;

Cname         : ID {
                    Cptr = CInstall($1, NULL);
                    $$ = Cptr;
              }
              | ID EXTENDS ID {
                    Cptr = CInstall($1, $3);
                    $$ = Cptr;
              }
              ;

/* MERGED Fields and Method Declarations to eliminate S/R conflicts */
ClassDeclList : ClassDeclList ClassDecl 
              | /* Empty */
              ;

ClassDecl     : TypeName ID ';' {
                    ClassFInstall(Cptr, $1, $2);
              }
            
              | TypeName ID '(' ParamList ')' ';' {
                char *mangled = mangleDecl($2, $4);
                ClassMInstall(Cptr, mangled, $1, $4);
                }
              ;

/* Member Method Definitions */
MethodDefList : MethodDefList MethodDef 
              | /* Empty */
              ;

MethodDef     : TypeName ID '(' ParamList ')' '{' LDeclBlock {
                    char *mangled = mangleDecl($2, $4);
                    struct Memberfunclist *m = ClassMLookup(Cptr, mangled);
                    
                    if (m == NULL) {
                        printf("Semantic Error: Method '%s' not declared in class.\n", mangled);
                        exit(1);
                    }
                    if (m->type != $1) {
                        printf("Semantic Error: Return type mismatch for method '%s'.\n", mangled);
                        exit(1);
                    }
                    
                    current_func_type = m->type;
                    InstallParameters($4);

                    /* INJECT IMPLICIT 'self' PARAMETER */
                    int param_count = count_params($4);
                    int self_binding = -(param_count + 4); 
                    LInstall("self", NULL, self_binding);
                    
                    struct LST_Node *self_node = LLookup("self");
                    self_node->ctype = Cptr;

              } Body '}' {
              
                    char *mangled = mangleDecl($2, $4);
                    struct Memberfunclist *m = ClassMLookup(Cptr, mangled);

                    if (m == NULL) {
                        printf("Compiler Error: Method definition not found: %s\n", mangled);
                        exit(1);
                    }
                    
                    fprintf(target_file, "F%d:\n", m->flabel);
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
                curr_type_defining = TInstall($1, 0, NULL);
             } TypeFieldDeclList '}' {
                curr_type_defining = NULL;
             }
             ;

TypeFieldDeclList : TypeFieldDeclList TypeFieldDecl
                  | /* Empty */
                  ;

TypeFieldDecl     : TypeName ID ';' {
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

GDeclBlock : DECL GDeclList ENDDECL 
           | DECL ENDDECL 
           | /* Empty */ 
           ;

GDeclList  : GDeclList GDecl 
           | GDecl 
           ;

GDecl      : TypeName { current_type = $1; } GVarList ';' ;

GVarList   : GVarList ',' GVar | GVar ;
GVar       : ID                      { GInstall($1, current_type, 1, NULL); }
           | ID '[' NUM ']'          { GInstall($1, current_type, $3, NULL); }
           | ID '(' ParamList ')'    { GInstall($1, current_type, 0, $3); } 
           | MUL ID                  { GInstall($2, current_type, 1, NULL); }
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

FDefList   : FDefList FDef 
           | /* Empty */
           ;

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
                current_func_type = g->type; 

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
LDecl : TypeName { current_type = $1; } LVarList ';' ;

LVarList
    : LVarList ',' ID {
        LInstall($3, current_type, local_binding);

        if (CLookup(current_type->name) != NULL)
            local_binding += 2;
        else
            local_binding += 1;
    }
    | LVarList ',' MUL ID {
        LInstall($4, current_type, local_binding);
        if (CLookup(current_type->name) != NULL) local_binding += 2;
        else local_binding += 1;
    }
    | ID {
        LInstall($1, current_type, local_binding);

        if (CLookup(current_type->name) != NULL)
            local_binding += 2;
        else
            local_binding += 1;
    }
    | MUL ID {
        LInstall($2, current_type, local_binding);
        if (CLookup(current_type->name) != NULL) local_binding += 2;
        else local_binding += 1;
    }
    ;

/* ========================================== */
/* Main Block                                 */
/* ========================================== */

/* Changed INT MAIN to TypeName MAIN to eliminate INT lookahead conflict */
MainBlock  : TypeName MAIN '(' ')' '{' LDeclBlock {
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

stmt : READ '(' Lvalue ')' ';' { 
            $$ = createTree(0, TLookup("void"), NULL, NODE_READ, $3, NULL); 
       }
     | WRITE '(' expr ')' ';' { $$ = createTree(0, TLookup("void"), NULL, NODE_WRITE, $3, NULL); }
     | Lvalue ASSIGN expr ';' { 
            $$ = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, $1, $3); 
       }
     | FREE '(' Lvalue ')' ';' {
            $$ = createTree(0, TLookup("void"), NULL, NODE_FREE, $3, NULL);
     }
     | DELETE '(' Lvalue ')' ';' {
            $$ = createTree(0, TLookup("void"), NULL, NODE_DELETE, $3, NULL);
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
            $$ = createTree(0, TLookup("void"), NULL, NODE_RET, $2, NULL);
       }
    | FOR '(' stmt expr ';' stmt ')' '{' slist '}'            { 
        struct tnode *body_update = createTree(0, TLookup("void"), NULL, NODE_CONN, $9, $6);
        struct tnode *while_loop = createTree(0,TLookup("void"), NULL, NODE_WHILE, $4, body_update);
        $$ = createTree(0, TLookup("void"), NULL, NODE_CONN, $3, while_loop);
     }

    | Lvalue INC ';' {
            struct tnode *one = createTree(1, TLookup("int"), NULL, NODE_NUM, NULL, NULL);
            struct tnode *add = createTree('+', TLookup("int"), NULL, NODE_OP, $1, one);
            $$ = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, $1, add);
       }
     | Lvalue DEC ';' {
            struct tnode *one = createTree(1, TLookup("int"), NULL, NODE_NUM, NULL, NULL);
            struct tnode *sub = createTree('-', TLookup("int"), NULL, NODE_OP, $1, one);
            $$ = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, $1, sub);
       }
     | SWITCH '(' expr ')' '{' CaseList '}' {
          /* NODE_SWITCH: left = condition, right = linked list of cases */
          $$ = createTree(0, TLookup("void"), NULL, NODE_SWITCH, $3, $6);
     }
     | Lvalue PLUS_EQ expr ';' { 
            struct tnode *op = createTree('+', TLookup("int"), NULL, NODE_OP, $1, $3);
            $$ = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, $1, op); 
       }
     | Lvalue MINUS_EQ expr ';' { 
            struct tnode *op = createTree('-', TLookup("int"), NULL, NODE_OP, $1, $3);
            $$ = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, $1, op); 
       }
     | Lvalue MUL_EQ expr ';' { 
            struct tnode *op = createTree('*', TLookup("int"), NULL, NODE_OP, $1, $3);
            $$ = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, $1, op); 
       }
     | Lvalue DIV_EQ expr ';' { 
            struct tnode *op = createTree('/', TLookup("int"), NULL, NODE_OP, $1, $3);
            $$ = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, $1, op); 
       }
     | Lvalue MOD_EQ expr ';' { 
            struct tnode *op = createTree('%', TLookup("int"), NULL, NODE_OP, $1, $3);
            $$ = createTree(0, TLookup("void"), NULL, NODE_ASSIGN, $1, op); 
       }
     ;
CaseList : CaseStmt CaseList {
          $$ = createTree(0, TLookup("void"), NULL, NODE_CONN, $1, $2);
     }
     | CaseStmt {
          $$ = $1;
     }
     ;

CaseStmt : CASE expr ':' slist {
          /* NODE_CASE: left = case value, right = body */
          $$ = createTree(0, TLookup("void"), NULL, NODE_CASE, $2, $4);
     }
     | DEFAULT ':' slist {
          /* NODE_DEFAULT: left = body */
          $$ = createTree(0, TLookup("void"), NULL, NODE_DEFAULT, $3, NULL);
     }
     ;

Lvalue : ID {
        $$ = createTree(0, NULL, $1, NODE_VAR, NULL, NULL);

        if ($$->type != NULL) {
            $$->ctype = CLookup($$->type->name);
        }
    }   
       | MUL Lvalue %prec USTAR { $$ = createTree(0, $2->type, NULL, NODE_PTR_DEREF, $2, NULL); }
       | SELF {
    $$ = createTree(0, NULL, "self", NODE_SELF, NULL, NULL);
    $$->Lentry = LLookup("self");
    $$->ctype = Cptr;

    if ($$->Lentry == NULL) {
        printf("Semantic Error: 'self' is not defined here.\n");
        exit(1);
    }
}
       | ID '[' expr ']' {
            struct tnode *v = createTree(0, NULL, $1, NODE_VAR, NULL, NULL);
            $$ = createTree(0, v->type, NULL, NODE_ARRAY, v, $3);
       }
       | Lvalue DOT ID {
            struct Fieldlist *f = NULL;
            if ($1->ctype != NULL) {
                f = ClassFLookup($1->ctype, $3);
            } else {
                f = FLookup($1->type, $3);
            }
            if (!f) {
                printf("Semantic Error: Field '%s' does not exist.\n", $3); exit(1);
            }
            $$ = createTree(f->fieldIndex, f->type, $3, NODE_FIELD, $1, NULL);
            $$->Fentry = f;
            $$->ctype = f->ctype;
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

expr : Lvalue             { $$ = $1; }
        | Lvalue ASSIGN expr {$$ = createTree(0, $1->type, NULL,NODE_ASSIGN, $1, $3);}
     | INIT '(' ')'       { $$ = createTree(0, TLookup("int"), NULL, NODE_INIT, NULL, NULL); }
     | ALLOC '(' ')'      { $$ = createTree(0, TLookup("void"), NULL, NODE_ALLOC, NULL, NULL); }
     | NULL_TOK           { $$ = createTree(0, TLookup("null"), NULL, NODE_NULL, NULL, NULL); }
     | NEW '(' ID ')' {
            struct Classtable *c = CLookup($3);

            if (c == NULL) {
                printf("Semantic Error: Class '%s' not found.\n", $3);
                exit(1);
            }

            struct tnode *classNode =
                createTree(0, NULL, $3, NODE_NULL, NULL, NULL);

            classNode->ctype = c;

            $$ = createTree(0, TLookup("void"), NULL, NODE_NEW, classNode, NULL);
            $$->ctype = c;
        }
        | Lvalue DOT ID '(' ArgList ')' {
            struct Classtable *c = $1->ctype;
            if (c == NULL) {
                printf("Semantic Error: Left side is not an object.\n"); exit(1);
            }
            
            /* 1. Mangle the name using the arguments */
            char *mangled = mangleCall($3, $5);
            
            /* 2. Look up the mangled name (e.g., "add_int_int") */
            struct Memberfunclist *m = ClassMLookup(c, mangled);
            if (m == NULL) {
                printf("Semantic Error: Overloaded Method '%s' not found in class.\n", mangled); exit(1);
            }
            
            /* 3. Pass the mangled name into the AST node */
            struct tnode *funcNode = createTree(0, m->type, mangled, NODE_OBJ_FUNC_CALL, $1, $5);
            funcNode->ctype = c;
            $$ = funcNode;
     }
     | ID '(' ArgList ')' {
            struct GST_Node *g = GLookup($1);
            if (g == NULL) { 
                printf("Semantic Error: Function '%s' is not declared.\n", $1); 
                exit(1); 
            }
            struct tnode *funcNode = createTree(0, NULL, $1, NODE_VAR, NULL, NULL);
            funcNode->Gentry = g; 
            $$ = createTree(0, g->type, NULL, NODE_FUNC_CALL, funcNode, $3); 
       }
     | SUPER DOT ID '(' ArgList ')' {
            if (Cptr == NULL || Cptr->parentptr == NULL) {
                printf("Semantic Error: 'super' can only be used inside a subclass.\n");
                exit(1);
            }
            
            struct Memberfunclist *m = ClassMLookup(Cptr->parentptr, $3);
            if (m == NULL) {
                printf("Semantic Error: Method '%s' not found in parent class.\n", $3);
                exit(1);
            }
            
            /* Create a 'self' node to act as the base object */
            struct tnode *selfNode = createTree(0, NULL, "self", NODE_SELF, NULL, NULL);
            selfNode->Lentry = LLookup("self");
            selfNode->ctype = Cptr;
            
            /* Construct the super call node, strictly pointing to the PARENT class type */
            struct tnode *funcNode = createTree(0, m->type, $3, NODE_SUPER, selfNode, $5);
            funcNode->ctype = Cptr->parentptr;
            $$ = funcNode;
     }
     | expr PLUS expr   { $$ = createTree('+', TLookup("int"), NULL, NODE_OP, $1, $3); }
     | expr MINUS expr  { $$ = createTree('-', TLookup("int"), NULL, NODE_OP, $1, $3); }
     | expr MUL expr    { $$ = createTree('*', TLookup("int"), NULL, NODE_OP, $1, $3); }
     | expr DIV expr    { $$ = createTree('/', TLookup("int"), NULL, NODE_OP, $1, $3); }
     | expr MOD expr    { $$ = createTree('%', TLookup("int"), NULL, NODE_OP, $1, $3); }
     | expr LT expr     { $$ = createTree(LT, TLookup("boolean"), NULL, NODE_RELOP, $1, $3); }
     | expr GT expr     { $$ = createTree(GT, TLookup("boolean"), NULL, NODE_RELOP, $1, $3); }
     | expr LE expr     { $$ = createTree(LE, TLookup("boolean"), NULL, NODE_RELOP, $1, $3); }
     | expr GE expr     { $$ = createTree(GE, TLookup("boolean"), NULL, NODE_RELOP, $1, $3); }
     | expr EQ expr     { $$ = createTree(EQ, TLookup("boolean"), NULL, NODE_RELOP, $1, $3); }
     | expr NE expr     { $$ = createTree(NE, TLookup("boolean"), NULL, NODE_RELOP, $1, $3); }
     | expr AND expr    { $$ = createTree(AND, TLookup("boolean"), NULL, NODE_RELOP, $1, $3); }
     | expr OR expr {
            $$ = createTree(OR, TLookup("boolean"), NULL, NODE_RELOP, $1, $3);
        }
     | '(' expr ')'     { $$ = $2; }
     | NUM              { $$ = createTree($1, TLookup("int"), NULL, NODE_NUM, NULL, NULL); }
     | STRING           { $$ = createTree(0, TLookup("str"), $1, NODE_STR_VAL, NULL, NULL); }
     | NOT expr       { $$ = createTree(0, TLookup("boolean"), NULL, NODE_NOT, $2, NULL); }
     | expr '?' expr ':' expr {
            /* Group the true and false expressions into a CONN node, then attach to TERNARY */
            struct tnode *then_else = createTree(0, $3->type, NULL, NODE_CONN, $3, $5);
            $$ = createTree(0, $3->type, NULL, NODE_TERNARY, $1, then_else); 
       }
     | TRUE           { $$ = createTree(1, TLookup("boolean"), NULL, NODE_NUM, NULL, NULL); }
     | FALSE          { $$ = createTree(0, TLookup("boolean"), NULL, NODE_NUM, NULL, NULL); }
     | '&' Lvalue { $$ = createTree(0, TLookup("int"), NULL, NODE_PTR_ADDR, $2, NULL); }
     
     ;
%%

void yyerror(char const *s) { 
    extern char *yytext;
    printf("YYError: %s at token '%s'\n", s, yytext); 
}

void makeBootCode(void) {
    fprintf(target_file, "BOOT:\n");
    fprintf(target_file, "MOV SP, %d\n", getSP());
    
    if (ClassTableHead != NULL) {
        initializeVTables(ClassTableHead);
    }

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