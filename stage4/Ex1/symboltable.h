#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#define TYPE_VOID 0
#define TYPE_INT  1
#define TYPE_STR  2
#define TYPE_BOOL 3

struct GST_Node {
    char* name;             // name of the variable
    int type;               // type of the variable (TYPE_INT or TYPE_STR)
    int size;               // size of the type of the variable (always 1 here)
    int cols;
    int binding;            // stores the static memory address allocated
    struct GST_Node *next;
};

struct GST_Node* Lookup(char *name);
void Install(char *name, int type, int rows, int cols);
void printSymbolTable(void);
int getSP(void);

#endif