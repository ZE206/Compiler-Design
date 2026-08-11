%{
#include "y.tab.h"
%}


%%
[a-z] {yylval.character=*yytext; return DIGIT;}
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

