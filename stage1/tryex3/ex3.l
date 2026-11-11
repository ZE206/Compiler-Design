%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "ex3.h"
    #include "y.tab.h"
%}

%%
[0-9]+ {yylval.val=atoi(yytext); return NUM;}
"+" {return PLUS;}
"-" {return SUB;}
"*" {return MUL;}
"/" {return DIV;}
[ \t] {}
\n  {return '\n';}
%%

int yywrap(){
    return 1;
}