#ifndef EXPRTREE_H
#define EXPRTREE_H

/* ========================================== */
/* Type and Node Constants                    */
/* ========================================== */
#define TYPE_VOID 0
#define TYPE_INT  1
#define TYPE_STR  2
#define TYPE_BOOL 3
#define TYPE_INTPTR 4
#define TYPE_STRPTR 5
#define TYPE_TUPLE 6

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
#define NODE_FIELD        24

/* ========================================== */
/* Struct Definitions                         */
/* ========================================== */
struct ParamNode {
    char *name;
    int type;
    struct ParamNode *next;
};

struct FieldNode {
    char *name;
    int type;
    int offset;
    struct FieldNode *next;
};

struct TupleDefNode {
    char *name;
    struct FieldNode *fields;
    int size;
    struct TupleDefNode *next;
};

struct LST_Node {
    char *name;
    int type;
    int binding;
    struct TupleDefNode *tuptype;
    struct LST_Node *next;
};

struct GST_Node {
    char* name;
    int type;
    int size;
    int cols; /* Added back to fix array 2D compilation */
    int binding;
    struct ParamNode *paramlist; 
    int flabel;
    struct TupleDefNode *tuptype;
    struct GST_Node *next;
};

typedef struct tnode {
    int val;
    char* varname;
    int type;
    int nodetype;
    struct GST_Node *Gentry;
    struct LST_Node *Lentry;
    struct TupleDefNode *tuptype;
    struct tnode *left, *right;
} tnode;

/* ========================================== */
/* Global Variables exposed to Yacc           */
/* ========================================== */
extern int local_binding; 
extern struct TupleDefNode *current_tuple_type;

/* ========================================== */
/* Function Prototypes                        */
/* ========================================== */
struct tnode* createTree(int val, int type, char* varname, int nodetype, struct tnode *l, struct tnode *r);
int codeGen(struct tnode *t);
int codeGenAddress(struct tnode *t);

int getReg(void);
void freeReg(void);
int getLabel(void);
void pushLoop(int start, int end);
void popLoop(void);

/* Tuple Functions */
struct TupleDefNode* TupleInstall(char *name, struct FieldNode *fields);
struct TupleDefNode* TupleLookup(char *name);
struct FieldNode* GetField(struct TupleDefNode *tuple, char *fname);

/* Global Symbol Table */
void GInstall(char *name, int type, int size, struct ParamNode *paramlist, struct TupleDefNode *tuptype); 
struct GST_Node* GLookup(char *name); 
void Install(char *name, int type, int rows, int cols); 
struct GST_Node* Lookup(char *name); 
void printSymbolTable(void);
int getSP(void);

/* Local Symbol Table */
void LInstall(char *name, int type, int binding, struct TupleDefNode *tuptype);
struct LST_Node* LLookup(char *name);
void InstallParameters(struct ParamNode *paramlist);
void LST_reset();

#endif