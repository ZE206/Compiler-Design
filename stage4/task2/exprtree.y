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
%}

%union {
    int val;
    int type;
    char *varname;
    struct tnode *no;
}

%token DECL ENDDECL INT STR
%token BEGIN_TOK END_TOK READ WRITE ASSIGN
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE
%token LT GT LE GE EQ NE
%token REPEAT UNTIL CONTINUE BREAK

%token <val> NUM
%token <varname> ID STRING
%type <type> Type
%type <no> slist stmt expr

%nonassoc LT GT LE GE EQ NE
%left PLUS MINUS
%left MUL DIV

%%
program : Declarations BEGIN_TOK slist END_TOK ';' {
            printSymbolTable();

            /* 8-word XEXE Header */
            fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
            fprintf(target_file, "MOV SP, %d\n", getSP()); // Dynamic SP based on variables

            codeGen($3);

            /* Clean ExpOS Exit System Call (Exactly 5 Pushes) */
            int r = getReg();
            fprintf(target_file, "MOV R%d, \"Exit\"\n", r);
            fprintf(target_file, "PUSH R%d\n", r);      /* Arg0: Function Code */
            fprintf(target_file, "MOV R%d, 0\n", r);
            fprintf(target_file, "PUSH R%d\n", r);      /* Arg1 */
            fprintf(target_file, "PUSH R%d\n", r);      /* Arg2 */
            fprintf(target_file, "PUSH R%d\n", r);      /* Arg3 */
            fprintf(target_file, "PUSH R%d\n", r);      /* Ret */
            fprintf(target_file, "CALL 0\n");
            freeReg();

            fclose(target_file);
            exit(0);
        }
        | Declarations BEGIN_TOK END_TOK ';' { exit(0); }
        ;

Declarations : DECL DeclList ENDDECL | DECL ENDDECL ;
DeclList : DeclList Decl | Decl ;
Decl : Type VarList ';' ;
Type : INT { current_type = TYPE_INT; $$ = TYPE_INT; }
     | STR { current_type = TYPE_STR; $$ = TYPE_STR; }
     ;




VarList : VarList ',' ID { Install($3, current_type, 1); }
        | ID { Install($1, current_type, 1); }
        ;

slist : slist stmt { $$ = createTree(0, TYPE_VOID, NULL, NODE_CONN, $1, $2); }
      | stmt       { $$ = $1; }
      ;

stmt : READ '(' ID ')' ';' { 
            struct tnode *varNode = createTree(0, 0, $3, NODE_VAR, NULL, NULL);
            $$ = createTree(0, TYPE_VOID, NULL, NODE_READ, varNode, NULL); 
       }
     | WRITE '(' expr ')' ';' { $$ = createTree(0, TYPE_VOID, NULL, NODE_WRITE, $3, NULL); }
     | ID ASSIGN expr ';' { 
            struct tnode *varNode = createTree(0, 0, $1, NODE_VAR, NULL, NULL);
            $$ = createTree(0, TYPE_VOID, NULL, NODE_ASSIGN, varNode, $3); 
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
     ;

expr : expr PLUS expr   { $$ = createTree('+', TYPE_INT, NULL, NODE_OP, $1, $3); }
     | expr MINUS expr  { $$ = createTree('-', TYPE_INT, NULL, NODE_OP, $1, $3); }
     | expr MUL expr    { $$ = createTree('*', TYPE_INT, NULL, NODE_OP, $1, $3); }
     | expr DIV expr    { $$ = createTree('/', TYPE_INT, NULL, NODE_OP, $1, $3); }
     | expr LT expr     { $$ = createTree(LT, TYPE_BOOL, NULL, NODE_RELOP, $1, $3); }
     | expr GT expr     { $$ = createTree(GT, TYPE_BOOL, NULL, NODE_RELOP, $1, $3); }
     | expr LE expr     { $$ = createTree(LE, TYPE_BOOL, NULL, NODE_RELOP, $1, $3); }
     | expr GE expr     { $$ = createTree(GE, TYPE_BOOL, NULL, NODE_RELOP, $1, $3); }
     | expr EQ expr     { $$ = createTree(EQ, TYPE_BOOL, NULL, NODE_RELOP, $1, $3); }
     | expr NE expr     { $$ = createTree(NE, TYPE_BOOL, NULL, NODE_RELOP, $1, $3); }
     | '(' expr ')'     { $$ = $2; }
     | NUM              { $$ = createTree($1, TYPE_INT, NULL, NODE_NUM, NULL, NULL); }
     | STRING           { $$ = createTree(0, TYPE_STR, $1, NODE_STR_VAL, NULL, NULL); }
     | ID               { $$ = createTree(0, 0, $1, NODE_VAR, NULL, NULL); }
     ;
%%

void yyerror(char const *s) { printf("YYError: %s\n", s); }

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (fp) yyin = fp;
        else { printf("Error opening input file: %s\n", argv[1]); return 1; }
    }
    target_file = fopen("target.xsm", "w");
    if (!target_file) { printf("Error creating target.xsm\n"); return 1; }
    yyparse();
    return 0;
}