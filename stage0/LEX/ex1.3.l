%{
    #include <stdlib.h>
    #include <stdio.h>
    int charNum=0;
    int count=0;
%}

letters [a-zA-Z]


%%
A{letters}{2} {count++;}
.|\n ;
%%

int yywrap(void){
    return 1;
}

int main(int argc, char* argv[]){
    if (argc>1){
        yyin=fopen(argv[1],"r");
    }

    yylex();

    printf("\n%d",count);
    return 1;
}