#include "ex3.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX_REGS 19


int regCount = -1;

int getReg() {
    if(regCount < 19) {
        regCount++;
        return regCount;
    } else {
        fprintf(stderr, "Out of Registers!\n");
        exit(1);
    }
}

void freeReg() {
    if(regCount >= 0) {
        regCount--;
    }
}

struct tnode* makeLeafNode(int val) {
    struct tnode* newNode=(struct tnode*)malloc(sizeof(struct tnode));
    newNode->val=val;
    newNode->op=NULL;
    newNode->left=NULL;
    newNode->right=NULL;    
    return newNode;
}

struct tnode* makeOperatorNode(char op,struct tnode *l,struct tnode *r) {
    struct tnode* newNode=(struct tnode*)malloc(sizeof(struct tnode));
    newNode->op = malloc(sizeof(char)); // but why not directly assign op? ....cuz we need to allocate memory for the character to store it properly.
    *(newNode->op) = op;
    newNode->left=l;
    newNode->right=r;    
    return newNode;
}
void infix(struct tnode *t){
    if(t == NULL) {
        return;
    }
    if(t->op == NULL)
    {
        printf("%d ",t->val);
    }
    else{
        printf("( ");
        infix(t->left);
        printf("%c ",*(t->op));
        infix(t->right);
        printf(") ");
    }
}
void postfix(struct tnode *t){
    if(t == NULL) {
        return;
    }
    if(t->op == NULL)
    {
        printf("%d ",t->val);
    }
    else{
        postfix(t->left);
        postfix(t->right);
        printf("%c ",*(t->op));
    }
}

int codeGen(struct tnode *t,FILE* targetFile){
    if(t == NULL) {
        return 0;
    }
    if(t->op == NULL)
    {
        int reg = getReg();
        fprintf(targetFile, "MOV R%d, %d\n", reg, t->val);
        return reg;
    }
    else{
        int leftReg = codeGen(t->left, targetFile);
        int rightReg = codeGen(t->right, targetFile);
        switch(*(t->op)){
            case '+' : fprintf(targetFile, "ADD R%d, R%d\n", leftReg, rightReg);
                       break;
            case '-' : fprintf(targetFile, "SUB R%d, R%d\n", leftReg, rightReg);
                       break;
            case '*' : fprintf(targetFile, "MUL R%d, R%d\n", leftReg, rightReg);
                       break;
            case '/' : fprintf(targetFile, "DIV R%d, R%d\n", leftReg, rightReg);
                       break;
        }
        freeReg(); 
        return leftReg; 
    }
}

int evaluate(struct tnode *t){
    if(t == NULL) {
        return 0;
    }
    if(t->op == NULL)
    {
        return t->val;
    }
    else{
        switch(*(t->op)){
            case '+' : return evaluate(t->left) + evaluate(t->right);
                       break;
            case '-' : return evaluate(t->left) - evaluate(t->right);
                       break;
            case '*' : return evaluate(t->left) * evaluate(t->right);
                       break;
            case '/' : return evaluate(t->left) / evaluate(t->right);
                       break;
        }
    }
}