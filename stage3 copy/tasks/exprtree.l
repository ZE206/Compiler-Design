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

"if"        { return IF; }
"then"      { return THEN; }
"else"      { return ELSE; }
"endif"     { return ENDIF; }
"while"     { return WHILE; }
"do"        { return DO; }
"endwhile"  { return ENDWHILE; }
"continue"  { return CONTINUE;}
"break"     { return BREAK; }

"<="        { return LE; }
">="        { return GE; }
"=="        { return EQ; }
"!="        { return NE; }
"<"         { return LT; }
">"         { return GT; }

"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MUL; }
"/"         { return DIV; }
"="         { return ASSIGN; }

[0-9]+      { 
                yylval.no = createTree(atoi(yytext), TYPE_INT, NULL, NODE_NUM, NULL, NULL); 
                return NUM; 
            }

[a-z]       { 
                yylval.no = createTree(0, TYPE_INT, yytext, NODE_VAR, NULL, NULL); 
                return ID; 
            }

[ \t\n]+    ; /* Skip whitespace */
[;()=]      { return *yytext; }
.           { printf("Unknown character: %s\n", yytext); exit(1); }

%%

int yywrap(void) {
    return 1;
}