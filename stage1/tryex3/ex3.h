#include <stdio.h>
#include <stdlib.h>
typedef struct tnode{
    int val;
    char* op;
    struct tnode *left;
    struct tnode *right;
} tnode;
void freeReg();
int getReg();
void postfix(struct tnode *t);
void infix(struct tnode *t);
struct tnode* makeLeafNode(int val);
struct tnode* makeOperatorNode(char op,struct tnode *l,struct tnode *r); 
int codeGen(struct tnode *t,FILE* targetFile);
int evaluate(struct tnode *t);