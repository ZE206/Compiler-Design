%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>    
void yyerror(char const *s);
int yylex();
int main();
char *concat(char *op, char *left, char *right);
%}

%union {
    char *str;
}


%token NEWLINE

%token <str> DIGIT
%left '+' '-'
%left '*' '/'
%type <str> expr
%%
start: expr NEWLINE {printf("%s\n", $1);}
      ;

expr: expr '+' expr {$$=concat("+ ",$1, $3);}
     | expr '-' expr {$$=concat("- ",$1, $3);}
    | expr '*' expr {$$=concat("* ",$1, $3);}
    | expr '/' expr {$$=concat("/ ",$1, $3);}
    | DIGIT {$$=$1;}
    ;
%%

void yyerror(char const *s){
    printf("yyerror: %s\n", s);
}
char *concat(char *op, char *left, char *right){
    char *result = malloc(strlen(op) + strlen(left) + strlen(right) + 3);
    sprintf(result, "%s%s %s", op, left, right);
    return result;
}
int main(){
    yyparse();
    return 0;
}