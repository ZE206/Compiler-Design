#include "task1.h"
#include <stdlib.h>
#include <stdio.h>

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

struct tnode* makeLeafNode(int val) {
    struct tnode* newNode=(struct tnode*)malloc(sizeof(struct tnode));
    newNode->val=val;
    newNode->op=NULL;
    newNode->left=NULL;
    newNode->right=NULL;    
    return newNode;
}

// function to create a new operator node
struct tnode* makeOperatorNode(char op,struct tnode *l,struct tnode *r) {
    struct tnode* newNode=(struct tnode*)malloc(sizeof(struct tnode));
    newNode->op = malloc(sizeof(char)); // but why not directly assign op? ....cuz we need to allocate memory for the character to store it properly.
    *(newNode->op) = op;
    newNode->left=l;
    newNode->right=r;    
    return newNode;
}

// function to evaluate the expression tree
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