%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprtree.h"
#include "y.tab.h"
%}

%%

"decl"          { return DECL; }
"enddecl"       { return ENDDECL; }
"int"           { return INT; }
"str"           { return STR; }

"begin"         { return BEGIN_TOK; }
"end"           { return END_TOK; }
"read"          { return READ; }
"write"         { return WRITE; }
"if"            { return IF; }
"then"          { return THEN; }
"else"          { return ELSE; }
"endif"         { return ENDIF; }
"while"         { return WHILE; }
"do"            { return DO; }
"endwhile"      { return ENDWHILE; }
"repeat"        { return REPEAT; }
"until"         { return UNTIL; }
"break"         { return BREAK; }
"continue"      { return CONTINUE; }
"main"          { return MAIN; }
"return"        { return RETURN; }
"AND"           { return AND; }

"{"         { return *yytext; }
"}"         { return *yytext; }
"("         { return *yytext; }
")"         { return *yytext; }
","         { return *yytext; }

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
                    yylval.val = atoi(yytext);
                    return NUM;
                }

\"(\\.|[^\"\\])*\" {
                    /* Strip surrounding quotes */
                    int len = strlen(yytext);
                    char *str = (char*)malloc(len - 1);
                    strncpy(str, yytext + 1, len - 2);
                    str[len - 2] = '\0';
                    yylval.varname = str;
                    return STRING;
                }

[a-zA-Z][a-zA-Z0-9_]* {
                    yylval.varname = strdup(yytext);
                    return ID;
                }

[\[\]();,&]      { return *yytext; }
[ \t\n]         { /* skip whitespace */ }

.               {
                    fprintf(stderr, "Lexical Error: Unknown character '%s'\n", yytext);
                    exit(1);
                }

%%

int yywrap() {
    return 1;
}