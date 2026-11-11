%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprtree.h"
#include "y.tab.h"
%}

%%

"begin"         { return START; }
"end"           { return END; }
"read"          { return READ; }
"write"         { return WRITE; }

"if"            { return IF; }
"then"          { return THEN; }
"else"          { return ELSE; }
"endif"         { return ENDIF; }

"while"         { return WHILE; }
"do"            { return DO; }
"endwhile"      { return ENDWHILE; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MUL; }
"/"             { return DIV; }
"="             { return ASSIGN; }

"<"             { return LT; }
">"             { return GT; }
"<="            { return LE; }
">="            { return GE; }
"=="            { return EQ; }
"!="            { return NE; }

[0-9]+          {
                    yylval.nptr = createTree(atoi(yytext), TYPE_INT, NULL, NODE_NUM, NULL, NULL, NULL);
                    return NUM;
                }

[a-z]           {
                    yylval.nptr = createTree(0, TYPE_INT, yytext, NODE_VAR, NULL, NULL, NULL);
                    return ID;
                }

[();]           { return *yytext; }
[ \t\n]         { /* skip whitespace */ }

.               { 
                    fprintf(stderr, "Lexical Error: Unknown character '%s'\n", yytext); 
                    exit(1); 
                }

%%

int yywrap() {
    return 1;
}