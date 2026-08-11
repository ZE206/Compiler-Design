%{
#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"

int yylex(void);
void yyerror(char const *s);
extern FILE *yyin;
%}

%union{
    struct tnode* no;
    int val;
}

%type <no> expr program

%token <val> NUM
%token SUB PLUS MUL DIV


%%
program: expr '\n'   {    
    $$=$1;
    printf("Infix: ");
    infix($1);
    printf("\nPostfix: ");
    postfix($1);
    printf("\n\n");
    FILE* fp=fopen("target.xsm","w");
    if(fp==NULL){
        printf("Error opening file\n");
        exit(1);
    }

    fprintf(fp,"0\n2056\n0\n0\n0\n0\n0\n0\n");

    int resultReg = codeGen($1, fp);

    fprintf(fp,"MOV [4096],R%d\n",resultReg);

    
    fprintf(fp,"MOV R0,\"Write\"\n");
    fprintf(fp,"PUSH R0\n");
    fprintf(fp,"MOV R0,-2\n");
    fprintf(fp,"PUSH R0\n");
    fprintf(fp,"MOV R0, [4096]\n");
    fprintf(fp,"PUSH R0\n");
    fprintf(fp,"PUSH R0\n");
    fprintf(fp,"PUSH R0\n");
    fprintf(fp,"CALL 0\n");         

    
    fprintf(fp,"POP R0\nPOP R1\nPOP R1\nPOP R1\nPOP R1\n");

    /* 5. Exit System Call */
    fprintf(fp,"MOV R0, \"Exit\"\n");
    fprintf(fp,"PUSH R0\n");
    fprintf(fp,"PUSH R0\n");
    fprintf(fp,"PUSH R0\n");
    fprintf(fp,"PUSH R0\n");
    fprintf(fp,"PUSH R0\n");
    fprintf(fp,"CALL 0\n");         

    fclose(fp);
    printf("Successfully generated target.xsm!\n");
    exit(0);
};

expr    : PLUS expr expr    { $$ = makeOperatorNode('+', $2, $3); }
        | MUL expr expr     { $$ = makeOperatorNode('*', $2, $3); }
        | SUB expr expr     { $$ = makeOperatorNode('-', $2, $3); }
        | DIV expr expr     { $$ = makeOperatorNode('/', $2, $3); }
        | NUM               { $$ = makeLeafNode($1); }
        ;
%%

void yyerror(const char* s){
    printf("yyerror %s\n", s);      
}

int main(void) {
    yyparse();
    return 0;
}