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
    int val;
    int type;
    char* varname;
    int nodetype;
    struct tnode *left, *mid, *right;
} tnode;

struct tnode* createTree(int val, int type, char* varname, int nodetype, 
                         struct tnode *l, struct tnode *m, struct tnode *r);

/* Code Generation & Register Routines */
int codeGen(struct tnode *t);
int getReg(void);
void freeReg(void);
int getLabel(void);

#endif