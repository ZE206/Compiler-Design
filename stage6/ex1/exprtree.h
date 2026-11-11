#ifndef EXPRTREE_H
#define EXPRTREE_H

#include <stdio.h>

/* ========================================== */
/* Type and Node Constants                    */
/* ========================================== */
#define TYPE_VOID 0
#define TYPE_INT  1
#define TYPE_STR  2
#define TYPE_BOOL 3
#define TYPE_INTPTR 4
#define TYPE_STRPTR 5

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
#define NODE_FUNC_CALL    22
#define NODE_RET          23

/* STAGE 6: UDT & Dynamic Heap Nodes */
#define NODE_FIELD        24
#define NODE_INIT         25
#define NODE_ALLOC        26
#define NODE_FREE         27
#define NODE_NULL         28

struct Typetable;

/* ========================================== */
/* Struct Definitions                         */
/* ========================================== */
struct Fieldlist {
    char *name;
    int fieldIndex;              /* Offset: 0 to 7 */
    struct Typetable *type;
    struct Fieldlist *next;
};

struct Typetable {
    char *name;
    int size;                    /* 1 for primitive/pointers, <= 8 for UDT */
    struct Fieldlist *fields;
    struct Typetable *next;
};

struct ParamNode {
    char *name;
    struct Typetable *type;
    struct ParamNode *next;
};

struct LST_Node {
    char *name;
    struct Typetable *type;
    int binding;
    struct LST_Node *next;
};

struct GST_Node {
    char *name;
    struct Typetable *type;
    int size;
    int cols;                    /* Preserved for 2D arrays */
    int binding;
    struct ParamNode *paramlist; 
    int flabel;
    struct GST_Node *next;
};

typedef struct tnode {
    int val;
    char *varname;
    struct Typetable *type;
    int nodetype;
    struct GST_Node *Gentry;
    struct LST_Node *Lentry;
    struct Fieldlist *Fentry;
    struct tnode *left, *right;
} tnode;

/* ========================================== */
/* Global Variables exposed to Yacc           */
/* ========================================== */
extern int local_binding; 
extern struct Typetable *current_type;
extern struct Typetable *current_func_type;

/* ========================================== */
/* Function Prototypes                        */
/* ========================================== */
struct tnode* createTree(int val, struct Typetable *type, char *varname, int nodetype, struct tnode *l, struct tnode *r);
int codeGen(struct tnode *t);
int codeGenAddress(struct tnode *t);

int getReg(void);
void freeReg(void);
int getLabel(void);
void pushLoop(int start, int end);
void popLoop(void);

/* Type Table Management */
void TypeTableCreate(void);
struct Typetable* TLookup(char *name);
struct Typetable* TInstall(char *name, int size, struct Fieldlist *fields);
struct Fieldlist* FLookup(struct Typetable *type, char *name);
struct Fieldlist* FInstall(struct Typetable *type, char *name, char *type_name);

/* Global Symbol Table */
void GInstall(char *name, struct Typetable *type, int size, struct ParamNode *paramlist); 
struct GST_Node* GLookup(char *name); 
struct GST_Node* Lookup(char *name); 
void Install(char *name, struct Typetable *type, int rows, int cols); 
void printSymbolTable(void);
int getSP(void);

/* Local Symbol Table */
void LInstall(char *name, struct Typetable *type, int binding);
struct LST_Node* LLookup(char *name);
void InstallParameters(struct ParamNode *paramlist);
void LST_reset(void);

#endif