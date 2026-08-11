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
    char *str;
}


%token NEWLINE

%token <str> DIGIT
%left '+' '-'
%left '*' '/'

%%
start: expr NEWLINE {printf("\n");}
      ;

expr: expr '+' expr {printf("+");}
     | expr '-' expr {printf("-");}
    | expr '*' expr {printf("*");}
    | expr '/' expr {printf("/");}
    | DIGIT {printf("%s ", $1);}
    ;
%%

void yyerror(char const *s){
    printf("yyerror: %s\n", s);
}

int main(){
    yyparse();
    return 0;
}