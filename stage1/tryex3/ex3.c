#include <stdio.h>
#include <stdlib.h>
#include "ex3.h"


int regCount=-1;

int getReg(){
    if(regCount>=19){
        printf("Out of Registers\n");
        exit(1);
    }
    regCount++;
    return regCount;
}

void freeReg(){
    if(regCount>=0){
        regCount--;
    }
}

void postfix(struct tnode *t){
    if(t==NULL){
        return;
    }
    if(t->op==NULL){
        printf("%d ", t->val);
    } else {
        postfix(t->left);
        postfix(t->right);
        printf("%c ", *(t->op));
    }
}

struct tnode* makeLeafNode(int val){
    struct tnode* newNode=(struct tnode*)malloc(sizeof(struct tnode));
    newNode->val=val;
    newNode->op=NULL;
    newNode->left=NULL;
    newNode->right=NULL;    
    return newNode;
}

struct tnode* makeOperatorNode(char op, struct tnode *l, struct tnode *r){
    struct tnode* newNode=(struct tnode*)malloc(sizeof(struct tnode));
    newNode->op=malloc(sizeof(char));
    *(newNode->op)=op;
    newNode->left=l;
    newNode->right=r;
    return newNode;
}

int codeGen(struct tnode *t, FILE* targetFile){
    if(t==NULL){
        return 0;
    }
    if(t->op==NULL){
        int reg=getReg();
        fprintf(targetFile, "MOV R%d, %d\n",reg, t->val);
        return reg;
    }
    int leftReg=codeGen(t->left, targetFile);
    int rightReg=codeGen(t->right, targetFile);
    switch(*(t->op)){
        case '+':
            fprintf(targetFile, "ADD R%d, R%d\n", leftReg, rightReg);
            break;
        case '-':
            fprintf(targetFile, "SUB R%d, R%d\n", leftReg, rightReg);
            break;
        case '*':
            fprintf(targetFile, "MUL R%d, R%d\n", leftReg, rightReg);
            break;
        case '/':
            fprintf(targetFile, "DIV R%d, R%d\n", leftReg, rightReg);
            break;
        
    }
    freeReg();
    return leftReg;

}
