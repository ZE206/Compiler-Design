%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "exprtree.h"
    
    int yylex(void);
    void yyerror(char const *s);
    FILE *target_file;
    extern FILE *yyin;
%}

%union{
    struct tnode *no;
}

%token BEGIN_TOK END_TOK READ WRITE ASSIGN
%token <no> NUM ID
%type <no> program slist stmt expr

%left PLUS SUB
%left MUL DIV

%%

program: BEGIN_TOK slist END_TOK ';' {
    fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(target_file, "MOV SP, 4159\n");
    codeGen($2);

    int r=getReg();
    fprintf(target_file, "MOV R%d , \"Exit\"\n",r);
    fprintf(target_file, "PUSH R%d\n",r);
    fprintf(target_file, "PUSH R%d\n", r);
    fprintf(target_file, "PUSH R%d\n", r);
    fprintf(target_file, "PUSH R%d\n", r);
    fprintf(target_file, "PUSH R%d\n",r);
    fprintf(target_file, "CALL 0\n")

    fclose(target_file);
    exit(0);
    | BEGIN_TOK END_TOK ';'    {exit(0);}
    ;
}

slist: slist stmt   {$$=createTree(0,NODE_CONN, NULL, $1, $2);}
    | stmt          {$$=$1;}
    ;
stmt: READ '(' ID ')' ';'   {$$=createTree(0,NODE_READ,NULL,$3, NULL);}
    | WRITE '(' ID ')' ';'  {$$=createTree(0,NODE_WRITE,NULL, $3, NULL);}
    | ID ASSIGN expr ';'    {$$=createTree(0,NODE_ASSIGN, NULL, $1,$3);}
    ;
expr: expr PLUS expr    {$$=createTree('+',NODE_OP, NULL, $1,$3);}
    | expr SUB expr     {$$=createTree('-',NODE_OP,NULL, $1,$3);}
    | expr MUL expr     {$$=createTree('*',NODE_OP,NULL, $1,$3);}
    | expr DIV expr     {$$=createTree('/',NODE_OP, NULL,$1,$3);}
    | '(' expr ')'      {$$=$2;}
    |NUM                {$$=$1;}
    | ID                {$$=$1;}
    ;
%%
void yyerror(char const *s){
    printf("")
}