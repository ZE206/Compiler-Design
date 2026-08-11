%{
#include <stdio.h>
#include <stdlib.h>
#include "task1.h"
#include "y.tab.h"
%}

%%
[0-9]+ {yylval.val=atoi(yytext); return NUM;}
"+" {return PLUS;}
"-" {return SUB;}
"*" {return MUL;}
"/" {return DIV;}
[ \t] {}
\n   {return '\n';}
.       { return *yytext; }
%%

int yywrap(){
    return 1;
}