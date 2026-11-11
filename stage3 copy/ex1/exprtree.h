#ifndef EXPRTREE_H
#define EXPRTREE_H

#define TYPE_VOID 0
#define TYPE_INT  1
#define TYPE_BOOL 2

#define NODE_NUM        1
#define NODE_VAR        2
#define NODE_OP         3
#define NODE_RELOP      4
#define NODE_ASSIGN     5
#define NODE_READ       6
#define NODE_WRITE      7
#define NODE_CONN       8
#define NODE_IF         9
#define NODE_IF_ELSE    10
#define NODE_WHILE      11

typedef struct tnode {
    int val;                    /* Value of a number */
    int type;                   /* TYPE_INT, TYPE_BOOL, TYPE_VOID */
    char* varname;              /* Name of variable (for IDs) */
    int nodetype;               /* Node type identifier (NODE_*) */
    struct tnode *left, *mid, *right; /* Left, Middle, Right Subtrees */
} tnode;

/* Function to create AST nodes */
struct tnode* createTree(int val, int type, char* varname, int nodetype, 
                         struct tnode *l, struct tnode *m, struct tnode *r);

/* Task 1 - Exercise 1: AST Evaluator */
int evaluate(struct tnode *t);

#endif