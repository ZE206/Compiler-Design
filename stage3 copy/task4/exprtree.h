#ifndef EXPRTREE_H
#define EXPRTREE_H

#include "symboltable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Data Types for type checking */
#define TYPE_INT 1
#define TYPE_BOOL 0

/* Node Types (for arg nodetype) */
#define NODE_NUM 1
#define NODE_VAR 2
#define NODE_STR_VAL 3
#define NODE_OP 4
#define NODE_READ 5
#define NODE_WRITE 6
#define NODE_CONN 7
#define NODE_ASSIGN 8
#define NODE_IF 9
#define NODE_IF_ELSE 10
#define NODE_WHILE 11
#define NODE_RELOP 12
#define NODE_BREAK 13
#define NODE_CONTINUE 14

typedef struct tnode {
    int val;                    /* Value for numeric constants */
    int type;                   /* TYPE_INT or TYPE_BOOL */
    char *varname;              /* Variable name for VAR nodes */
    int nodetype;     
    struct GST_Node Gentry;          /* NODE_NUM, NODE_OP, NODE_IF, NODE_WHILE, etc. */
    struct tnode *left, *right; /* Left and right children */
} tnode;


struct tnode* createTree(int val, int type, char* varname, int nodetype, struct tnode *l, struct tnode *r);
int getReg(void);
void freeReg(void);
int getLabel(void);
int getMemoryAddress(char var);
int codeGen(struct tnode *t);

#endif