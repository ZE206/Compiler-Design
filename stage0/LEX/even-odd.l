%{
#include <stdlib.h>
#include <stdio.h>

int number_1;
int number_2;

%}

num  [0-9]*


%%

{num}[02468]    {printf("Even number [%d]",yyleng);return atoi(yytext);}
{num}[13579]    {printf("Odd number [%d]",yyleng);return atoi(yytext);}


%%

int yywrap(void)
{
    return 1;
}

int main(int argc, char* argv[])
{
    
    number_1=yylex();
    number_2=yylex();

    int diff =number_1-number_2;

    if(diff%2!=0){
        printf("\nYour inputs are no shit.");   
    }
        
    else{
        printf("\n You mofo, fuckin shi input u gave. type shi");
    }
        

    return 1;
}