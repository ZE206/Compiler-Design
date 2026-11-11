%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprtree.h"
#include "y.tab.h"
%}

%%

"type"          { return TYPE; }
"endtype"       { return ENDTYPE; }
"decl"          { return DECL; }
"enddecl"       { return ENDDECL; }
"int"           { return INT; }
"str"           { return STR; }
"null"          { return NULL_TOK; }

"alloc"         { return ALLOC; }
"initialize"    { return INIT; }
"free"          { return FREE; }

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

"class"     { return CLASS; }
"endclass"  { return ENDCLASS; }
"new"       { return NEW; }
"delete"    { return DELETE; }
"self"      { return SELF; }

"main"          { return MAIN; }
"return"        { return RETURN; }
"AND"           { return AND; }
"extends"   { return EXTENDS; }

"{"             { return *yytext; }
"}"             { return *yytext; }
"("             { return *yytext; }
")"             { return *yytext; }
","             { return *yytext; }
";"             { return *yytext; }
"."             { return DOT; }

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

[\[\]&]         { return *yytext; }
[ \t\n]         { /* skip whitespace */ }
"//"[^\n]*      { /* skip single-line comments */ }
"/*"([^*]|\*+[^/])*\*+"/" { /* skip multi-line comments */ }

.               {
                    fprintf(stderr, "Lexical Error: Unknown character '%s'\n", yytext);
                    exit(1);
                }

%%

int yywrap() {
    return 1;
}