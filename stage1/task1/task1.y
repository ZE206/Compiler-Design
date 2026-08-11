%{
#include "task1.h"
#include <stdio.h>
#include <stdlib.h>

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

%left PLUS SUB
%left MUL DIV

%%
program : expr '\n'      {$$=$1; printf("Infix: ");
                            infix($1);
                            printf("\n");
                            printf("Postfix: ");
                            postfix($1);
                            printf("\n\n");
                            printf("Answer: %d",evaluate($1));
                            exit(1);};
expr: expr PLUS expr    {$$=makeOperatorNode('+',$1,$3);}
    | expr MUL expr     {$$=makeOperatorNode('*',$1,$3);}
    | expr SUB expr     {$$=makeOperatorNode('-',$1,$3);}
    | expr DIV expr     {$$=makeOperatorNode('/',$1,$3);}
    | '(' expr ')'      { $$=$2; }
    | NUM               {$$=makeLeafNode($1);}
    ;
%%

void yyerror(char const *s){
    printf("yyerror %s\n",s);
}


int main(void) {
 yyparse();

 return 0;
}