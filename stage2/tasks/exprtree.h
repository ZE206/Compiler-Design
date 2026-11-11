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
    int val;                    /* Value for NUM, operator character for OP */
    int type;                   /* Node type: NODE_NUM, NODE_VAR, NODE_OP, etc. */
    char *varname;              /* Name of variable for VAR, READ, ASSIGN nodes */
    struct tnode *left, *right;  /* Left and right child pointers */
} tnode;

/* Function Declarations */
struct tnode* createTree(int val, int type, char* c, struct tnode *l, struct tnode *r);
int getReg(void);
void freeReg(void);
int getMemoryAddress(char var);
int codeGen(struct tnode *t);

#endif