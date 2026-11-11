#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprtree.h"

/* ======================================================== */
/* 1. TYPE TABLE IMPLEMENTATION                             */
/* ======================================================== */

static struct Typetable *TypeTableHead = NULL;

void TypeTableCreate(void) {
    TInstall("int", 1, NULL);
    TInstall("str", 1, NULL);
    TInstall("boolean", 1, NULL);
    TInstall("void", 0, NULL);
    TInstall("null", 0, NULL);
}

struct Typetable* TLookup(char *name) {
    struct Typetable *temp = TypeTableHead;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

struct Typetable* TInstall(char *name, int size, struct Fieldlist *fields) {
    if (TLookup(name) != NULL) {
        printf("Semantic Error: Type '%s' is already defined.\n", name);
        exit(1);
    }
    struct Typetable *newNode = (struct Typetable*)malloc(sizeof(struct Typetable));
    newNode->name = strdup(name);
    newNode->size = size;
    newNode->fields = fields;
    newNode->next = TypeTableHead;
    TypeTableHead = newNode;
    return newNode;
}

struct Fieldlist* FLookup(struct Typetable *type, char *name) {
    if (type == NULL) return NULL;
    struct Fieldlist *temp = type->fields;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

struct Fieldlist* FInstall(struct Typetable *type, char *name, char *type_name) {
    struct Typetable *ftype = TLookup(type_name);
    if (ftype == NULL) {
        printf("Semantic Error: Unknown field type '%s' in type '%s'.\n", type_name, type->name);
        exit(1);
    }
    
    if (FLookup(type, name) != NULL) {
        printf("Semantic Error: Duplicate field '%s' in type '%s'.\n", name, type->name);
        exit(1);
    }

    struct Fieldlist *newField = (struct Fieldlist*)malloc(sizeof(struct Fieldlist));
    newField->name = strdup(name);
    newField->type = ftype;
    newField->next = NULL;
    
    if (type->fields == NULL) {
        newField->fieldIndex = 0;
        type->fields = newField;
    } else {
        struct Fieldlist *curr = type->fields;
        int idx = 1;
        while (curr->next != NULL) {
            curr = curr->next;
            idx += 1;
        }
        if (idx >= 8) {
            printf("Semantic Error: User-defined type '%s' exceeds the 8-field limit.\n", type->name);
            exit(1);
        }
        newField->fieldIndex = idx;
        curr->next = newField;
    }
    type->size = newField->fieldIndex + 1;
    return newField;
}

/* ======================================================== */
/* 2. GLOBAL SYMBOL TABLE                                   */
/* ======================================================== */

static struct GST_Node *head = NULL;
static int mem_address = 4096; 
static int flabel_count = 0; 

struct LST_Node *LST_head = NULL; 
int local_binding = 1;

void LInstall(char *name, struct Typetable *type, int binding) {
    if (LLookup(name) != NULL) {
        printf("Semantic Error: Local variable '%s' is already declared.\n", name);
        exit(1);
    }
    struct LST_Node *temp = (struct LST_Node*)malloc(sizeof(struct LST_Node));
    temp->name = strdup(name);
    temp->type = type;
    temp->binding = binding;

    temp->next = LST_head;
    LST_head = temp;
}

struct LST_Node* LLookup(char *name) {
    struct LST_Node *temp = LST_head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

void LST_reset(void) {
    struct LST_Node *temp;
    while (LST_head != NULL) {
        temp = LST_head;
        LST_head = LST_head->next;
        free(temp->name);
        free(temp);
    }
    local_binding = 1;
}

struct GST_Node* GLookup(char *name) {
    struct GST_Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

struct GST_Node* Lookup(char *name) {
    return GLookup(name);
}

void GInstall(char *name, struct Typetable *type, int size, struct ParamNode *paramlist) {
    if (GLookup(name) != NULL) {
        printf("Semantic Error: Identifier '%s' is already declared.\n", name);
        exit(1);
    }
    
    struct GST_Node *newnode = (struct GST_Node*)malloc(sizeof(struct GST_Node));
    newnode->name = strdup(name);
    newnode->type = type;
    newnode->size = size;
    newnode->paramlist = paramlist; 
    newnode->cols = 0;
    
    if (paramlist != NULL || (size == 0 && paramlist == NULL)) {
        newnode->flabel = flabel_count++;
        newnode->binding = -1;
    } else {
        newnode->flabel = -1;
        newnode->binding = mem_address;
        mem_address += size;
    }
    
    newnode->next = head;
    head = newnode;
}

void Install(char *name, struct Typetable *type, int rows, int cols) {
    int total = rows * cols;
    if (total == 0) total = 1;
    GInstall(name, type, total, NULL);
}

void InstallParameters(struct ParamNode *paramlist) {
    int count = 0;
    struct ParamNode *temp = paramlist;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    temp = paramlist;
    int current_binding = -(count + 2); 
    
    while (temp != NULL) {
        LInstall(temp->name, temp->type, current_binding);
        current_binding++; 
        temp = temp->next;
    }
}

int getSP(void) {
    return mem_address - 1; 
}

void printSymbolTable(void) {
    struct GST_Node *temp = head;
    printf("\n========= GLOBAL SYMBOL TABLE =========\n");
    printf("%-10s %-12s %-10s %-10s %-10s\n", "NAME", "TYPE", "SIZE", "BINDING", "FLABEL");
    while (temp != NULL) {
        printf("%-10s %-12s %-10d %-10d %-10d\n", 
               temp->name, 
               temp->type ? temp->type->name : "void", 
               temp->size, 
               temp->binding, 
               temp->flabel);
        temp = temp->next;
    }
    printf("=======================================\n\n");
}