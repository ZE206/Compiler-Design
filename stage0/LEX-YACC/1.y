%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>    
void yyerror(char const *s);
int yylex();
int main();

%}

%union {
    char character;
}


%token NEWLINE

%token <character> DIGIT
%left '+' '-'
%left '*' '/'

%%
start: expr NEWLINE {printf("\n");}
      ;

expr: expr '+' expr {printf("+");}
     | expr '-' expr {printf("-");}
    | expr '*' expr {printf("*");}
    | expr '/' expr {printf("/");}
    | DIGIT {printf("%c", $1);}
    ;
%%

void yyerror(char const *s){
    printf("yyerror: %s\n", s);
}

int main(){
    yyparse();
    return 0;
}