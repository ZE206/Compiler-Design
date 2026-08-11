%{
#include <stdlib.h>
#include <stdio.h>

int floatCount=0;
int integerCount=0;
%}

digits [0-9]
float ({digits}+\.{digits}*|{digits}*\.{digits}+) 

%%
{float} {floatCount++;}
{digits}+ {integerCount++;}
%%

int yywrap(void){
    return 1;
}

int main(int argc, char* argv[]){
    if(argc>1){
        yyin=fopen(argv[1],"r");
    }
    yylex();
    printf("floating Numbers: %d, Integer Count: %d",floatCount, integerCount);
    return 1;
}
