%{
#include <stdlib.h>
#include <stdio.h>

int lines=0;
int chars=0;
int words=0;
%}

digits [0-9]*
letters [a-zA-Z]*
op [-+=*/]*

%%
\n {lines++; chars++;}
[^ \n\t]+ {words++; chars+=yyleng;}
. {chars++;}
%%

int yywrap(void){
    return 1;
}

int main(int argc, char* argv[]){
    if(argc>1){
        yyin=fopen(argv[1],"r");
    }
    yylex();
    printf("line: %d, chars: %d, words: %d",lines,chars, words);
    return 1;
}
