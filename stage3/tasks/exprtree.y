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
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE
%token LT GT LE GE EQ NE
%token CONTINUE BREAK
%token <no> NUM ID
%type <no> program slist stmt expr

%nonassoc LT GT LE GE EQ NE
%left PLUS MINUS
%left MUL DIV

%%

program : BEGIN_TOK slist END_TOK ';' {
            /* 8-word XEXE Header */
            fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
            fprintf(target_file, "MOV SP, 4159\n");

            codeGen($2);

            /* Exit System Call */
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

slist : slist stmt     { $$ = createTree(0, 0, NULL, NODE_CONN, $1, $2); }
      | stmt           { $$ = $1; }
      ;

stmt : READ '(' ID ')' ';'                            { $$ = createTree(0, 0, NULL, NODE_READ, $3, NULL); }
     | WRITE '(' expr ')' ';'                         { $$ = createTree(0, 0, NULL, NODE_WRITE, $3, NULL); }
     | ID ASSIGN expr ';'                             { $$ = createTree(0, 0, NULL, NODE_ASSIGN, $1, $3); }
     | IF '(' expr ')' THEN slist ELSE slist ENDIF ';' { 
            /* Condition on left; THEN/ELSE connector on right */
            struct tnode *then_else = createTree(0, 0, NULL, NODE_CONN, $6, $8);
            $$ = createTree(0, 0, NULL, NODE_IF_ELSE, $3, then_else); 
       }
     | IF '(' expr ')' THEN slist ENDIF ';'            { $$ = createTree(0, 0, NULL, NODE_IF, $3, $6); }
     | WHILE '(' expr ')' DO slist ENDWHILE ';'       { $$ = createTree(0, 0, NULL, NODE_WHILE, $3, $6); }
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