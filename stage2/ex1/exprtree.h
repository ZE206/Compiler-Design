#ifndef EXPRTREE_H
#define EXPRTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODE_NUM 1
#define NODE_VAR 2
#define NODE_OP 3
#define NODE_READ 4
#define NODE_WRITE 5
#define NODE_CONN 6
#define NODE_ASSIGN 7

typedef struct tnode {
    int val;                    
    int type;                   
    char *varname;              
    struct tnode *left, *right;  
} tnode;


struct tnode* createTree(int val, int type, char* c, struct tnode *l, struct tnode *r);
int evaluate(struct tnode *t);

#endif