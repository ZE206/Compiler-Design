#ifndef EXPRTREE_H
#define EXPRTREE_H
#include "symboltable.h"

#define NODE_NUM          1
#define NODE_VAR          2
#define NODE_STR_VAL      3
#define NODE_OP           4
#define NODE_RELOP        5
#define NODE_ASSIGN       6
#define NODE_READ         7
#define NODE_WRITE        8
#define NODE_CONN         9
#define NODE_IF           10
#define NODE_IF_ELSE      11
#define NODE_WHILE        12
#define NODE_DO_WHILE     13
#define NODE_REPEAT_UNTIL 14
#define NODE_BREAK        15
#define NODE_CONTINUE     16
#define NODE_ARRAY        17
#define NODE_ARRAY_2D     18
#define NODE_INDEX        19
#define NODE_PTR_DEREF    20
#define NODE_PTR_ADDR     21

typedef struct tnode {
    int val;                    // value of the constant
    char* varname;              // name of the variable or string constant
    int type;                   // type of the variable/expression
    int nodetype;               // node type information
    struct GST_Node *Gentry;    // pointer to GST entry
    struct tnode *left, *right; // left and right branches
} tnode;

struct tnode* createTree(int val, int type, char* varname, int nodetype, struct tnode *l, struct tnode *r);

int getReg(void);
void freeReg(void);
int getLabel(void);
void pushLoop(int start, int end);
void popLoop(void);
int codeGen(struct tnode *t);

#endif