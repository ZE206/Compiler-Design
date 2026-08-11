%{
#include "y.tab.h"
#include <string.h>
%}


%%
[a-z]+ {yylval.str=strdup(yytext); return DIGIT;}
"+" {return *yytext;}
"-" {return *yytext;}
"*" {return *yytext;}
"/" {return *yytext;}
[ \t] {}
\n   {return NEWLINE;}
%%

int yywrap(){
    return 1;
}

