#ifndef  SYMBOLTABLE_H
#define SYMBOLTABLE_H

#define TYPE_VOID 0
#define TYPE_INT 1
#define TYPE_STR 2
#define TYPE_BOOL 3

struct GST_Node{
    char* name;
    int type;
    int size;
    int binding;
    struct GST_Node *next;
};

struct GST_Node* Lookup(char *name);
struct GST_Node* Install(char *name, int type, int size);
void printSymbolTable(void);
int getSP(void);
#endif