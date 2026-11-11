%{
#include <stdio.h>
#include <stdlib.h>
#include "exprtree.h"

int yylex(void);
void yyerror(char const *s);
extern FILE *yyin;
FILE *target_file;
%}

%union {
    struct tnode *nptr;
}

%token START END READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE
%token PLUS MINUS MUL DIV ASSIGN
%token LT GT LE GE EQ NE
%token <nptr> NUM ID
%type <nptr> Program Slist Stmt InputStmt OutputStmt AsgStmt IfStmt WhileStmt Expr

%left PLUS MINUS
%left MUL DIV
%nonassoc LT GT LE GE EQ NE

%%

Program : START Slist END ';' {
            $$ = $2;
            
            /* 1. Write XEXE 8-Word Header */
            fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
            
            /* 2. Initialize Stack Pointer past static variables ('a'-'z' are 4096-4121) */
            fprintf(target_file, "MOV SP, 4121\n");
            
            /* 3. Generate Code from AST */
            codeGen($2);
            
            /* 4. Emit Clean Halt / Exit System Call */
            int r = getReg();
            fprintf(target_file, "MOV R%d, \"Exit\"\n", r);
            fprintf(target_file, "PUSH R%d\n", r);
            fprintf(target_file, "PUSH R%d\n", r);
            fprintf(target_file, "PUSH R%d\n", r);
            fprintf(target_file, "PUSH R%d\n", r);
            fprintf(target_file, "PUSH R%d\n", r);
            fprintf(target_file, "CALL 0\n");
            
            fclose(target_file);
            exit(0);
        }
        | START END ';' {
            exit(0);
        }
        ;

Slist   : Slist Stmt        { $$ = createTree(0, TYPE_VOID, NULL, NODE_CONN, $1, NULL, $2); }
        | Stmt              { $$ = $1; }
        ;

Stmt    : InputStmt         { $$ = $1; }
        | OutputStmt        { $$ = $1; }
        | AsgStmt           { $$ = $1; }
        | IfStmt            { $$ = $1; }
        | WhileStmt         { $$ = $1; }
        ;

InputStmt : READ '(' ID ')' ';' {
            $$ = createTree(0, TYPE_VOID, NULL, NODE_READ, $3, NULL, NULL);
          }
          ;

OutputStmt : WRITE '(' Expr ')' ';' {
             $$ = createTree(0, TYPE_VOID, NULL, NODE_WRITE, $3, NULL, NULL);
           }
           ;

AsgStmt : ID ASSIGN Expr ';' {
            $$ = createTree(0, TYPE_VOID, NULL, NODE_ASSIGN, $1, NULL, $3);
        }
        ;

IfStmt  : IF '(' Expr ')' THEN Slist ELSE Slist ENDIF ';' {
            $$ = createTree(0, TYPE_VOID, NULL, NODE_IF_ELSE, $3, $6, $8);
        }
        | IF '(' Expr ')' THEN Slist ENDIF ';' {
            $$ = createTree(0, TYPE_VOID, NULL, NODE_IF, $3, $6, NULL);
        }
        ;

WhileStmt : WHILE '(' Expr ')' DO Slist ENDWHILE ';' {
              $$ = createTree(0, TYPE_VOID, NULL, NODE_WHILE, $3, NULL, $6);
          }
          ;

Expr    : Expr PLUS Expr    { $$ = createTree('+', TYPE_INT, NULL, NODE_OP, $1, NULL, $3); }
        | Expr MINUS Expr   { $$ = createTree('-', TYPE_INT, NULL, NODE_OP, $1, NULL, $3); }
        | Expr MUL Expr     { $$ = createTree('*', TYPE_INT, NULL, NODE_OP, $1, NULL, $3); }
        | Expr DIV Expr     { $$ = createTree('/', TYPE_INT, NULL, NODE_OP, $1, NULL, $3); }
        | Expr LT Expr      { $$ = createTree(LT, TYPE_BOOL, NULL, NODE_RELOP, $1, NULL, $3); }
        | Expr GT Expr      { $$ = createTree(GT, TYPE_BOOL, NULL, NODE_RELOP, $1, NULL, $3); }
        | Expr LE Expr      { $$ = createTree(LE, TYPE_BOOL, NULL, NODE_RELOP, $1, NULL, $3); }
        | Expr GE Expr      { $$ = createTree(GE, TYPE_BOOL, NULL, NODE_RELOP, $1, NULL, $3); }
        | Expr EQ Expr      { $$ = createTree(EQ, TYPE_BOOL, NULL, NODE_RELOP, $1, NULL, $3); }
        | Expr NE Expr      { $$ = createTree(NE, TYPE_BOOL, NULL, NODE_RELOP, $1, NULL, $3); }
        | '(' Expr ')'      { $$ = $2; }
        | NUM               { $$ = $1; }
        | ID                { $$ = $1; }
        ;

%%

void yyerror(char const *s) {
    printf("yyerror: %s\n", s);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (fp) yyin = fp;
    }
    target_file = fopen("target.xsm", "w");
    if (!target_file) {
        printf("Error opening target.xsm\n");
        return 1;
    }
    yyparse();
    return 0;
}