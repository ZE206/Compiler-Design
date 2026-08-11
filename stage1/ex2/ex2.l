%{
#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"      /* Must match the header */
#include "y.tab.h"    /* Yacc generated file */
%}


%%
[0-9]+ {yylval.val=atoi(yytext); return NUM;}
"+" {return PLUS;}
"-" {return SUB;}
"*" {return MUL;}
"/" {return DIV;}
[ \t] {}
\n   {return '\n';}
%%

int yywrap(){
    return 1;
}