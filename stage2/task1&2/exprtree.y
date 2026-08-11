%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "exprtree.h"

    int yylex(void);
    void yyerror(char const *s);

    FILE *target_file;
    extern FILE *yyin;
%}

%union {
    struct tnode *no;
}

%token BEGIN_TOK END_TOK READ WRITE ASSIGN
%token <no> NUM ID
%type <no> program slist stmt expr

%left PLUS MINUS
%left MUL DIV

%%

program : BEGIN_TOK slist END_TOK ';' {
            /* 8-word XEXE Header required by ExpOS / XSM */
            fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
            fprintf(target_file, "MOV SP, 4159\n");
            /* Generate code for AST */
            codeGen($2);

            /* Emit Exit System Call */
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
        | BEGIN_TOK END_TOK ';' { exit(0); }
        ;

slist : slist stmt     { $$ = createTree(0, NODE_CONN, NULL, $1, $2); }
      | stmt           { $$ = $1; }
      ;

stmt : READ '(' ID ')' ';'    { $$ = createTree(0, NODE_READ, NULL, $3, NULL); }
     | WRITE '(' expr ')' ';' { $$ = createTree(0, NODE_WRITE, NULL, $3, NULL); }
     | ID ASSIGN expr ';'     { $$ = createTree(0, NODE_ASSIGN, NULL, $1, $3); }
     ;

expr : expr PLUS expr   { $$ = createTree('+', NODE_OP, NULL, $1, $3); }
     | expr MINUS expr  { $$ = createTree('-', NODE_OP, NULL, $1, $3); }
     | expr MUL expr    { $$ = createTree('*', NODE_OP, NULL, $1, $3); }
     | expr DIV expr    { $$ = createTree('/', NODE_OP, NULL, $1, $3); }
     | '(' expr ')'     { $$ = $2; }
     | NUM              { $$ = $1; }
     | ID               { $$ = $1; }
     ;

%%

void yyerror(char const *s) {
    printf("YYError: %s\n", s);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (fp) {
            yyin = fp;
        } else {
            printf("Error opening input file: %s\n", argv[1]);
            return 1;
        }
    }

    target_file = fopen("target.xsm", "w");
    if (!target_file) {
        printf("Error creating target.xsm\n");
        return 1;
    }

    yyparse();
    return 0;
}