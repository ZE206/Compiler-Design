%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "exprtree.h"
    #include "y.tab.h"
%}

%%

"begin"     { return BEGIN_TOK; }
"end"       { return END_TOK; }
"read"      { return READ; }
"write"     { return WRITE; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MUL; }
"/"         { return DIV; }
"="         { return ASSIGN; }
[0-9]+      { 
                yylval.no = createTree(atoi(yytext), NODE_NUM, NULL, NULL, NULL); 
                return NUM; 
            }
[a-z]       { 
                yylval.no = createTree(0, NODE_VAR, yytext, NULL, NULL); 
                return ID; 
            }
[ \t\n]+    ; /* Ignore whitespace */
[;()=]      { return *yytext; }
.           { printf("Unknown character: %s\n", yytext); exit(1); }

%%

int yywrap(void) {
    return 1;
}