#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprtree.h"

static struct GST_Node *head = NULL;
static int mem_address = 4096; 
static int flabel_count = 0; 

struct LST_Node *LST_head = NULL; 
int local_binding = 1;

struct TupleDefNode *TupleTableHead = NULL;
struct TupleDefNode *current_tuple_type = NULL;

/* ========================================== */
/* Tuple Schema Functions                     */
/* ========================================== */

struct TupleDefNode* TupleInstall(char *name, struct FieldNode *fields) {
    /* If the tuple schema is already defined, return it instead of throwing an error */
    struct TupleDefNode *existing = TupleLookup(name);
    if (existing != NULL) {
        return existing;
    }
    
    struct TupleDefNode *newnode = (struct TupleDefNode*)malloc(sizeof(struct TupleDefNode));
    newnode->name = strdup(name);
    newnode->fields = fields;
    
    int size = 0;
    struct FieldNode *temp = fields;
    while(temp) { 
        temp->offset = size++; 
        temp = temp->next; 
    }
    newnode->size = size;
    
    newnode->next = TupleTableHead;
    TupleTableHead = newnode;
    return newnode;
}

struct TupleDefNode* TupleLookup(char *name) {
    struct TupleDefNode *temp = TupleTableHead;
    while(temp) {
        if(strcmp(temp->name, name) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

struct FieldNode* GetField(struct TupleDefNode *tuple, char *fname) {
    if (tuple == NULL) return NULL;
    struct FieldNode *temp = tuple->fields;
    while(temp) {
        if(strcmp(temp->name, fname) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

/* ========================================== */
/* Local Symbol Table                         */
/* ========================================== */

void LInstall(char *name, int type, int binding, struct TupleDefNode *tuptype) {
    if(LLookup(name) != NULL){
        printf("Semantic Error: Local variable '%s' is already declared. \n", name);
        exit(1);
    }
    struct LST_Node* temp = (struct LST_Node*)malloc(sizeof(struct LST_Node));
    temp->name = strdup(name);
    temp->type = type;
    temp->binding = binding;
    temp->tuptype = tuptype;

    temp->next = LST_head;
    LST_head = temp;
}

struct LST_Node* LLookup(char *name) {
    struct LST_Node *temp = LST_head;
    while(temp != NULL){
        if(strcmp(temp->name, name) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

void LST_reset() {
    struct LST_Node *temp;
    while(LST_head != NULL){
        temp = LST_head;
        LST_head = LST_head->next;
        free(temp->name);
        free(temp);
    }
    local_binding = 1;
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
        /* Parameters do not support tuples yet per requirements, so pass NULL for tuptype */
        LInstall(temp->name, temp->type, current_binding, NULL);
        current_binding++; 
        temp = temp->next;
    }
}

/* ========================================== */
/* Global Symbol Table                        */
/* ========================================== */

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

void GInstall(char *name, int type, int size, struct ParamNode *paramlist, struct TupleDefNode *tuptype) {
    if (GLookup(name) != NULL) {
        printf("Semantic Error: Identifier '%s' is already declared.\n", name);
        exit(1);
    }
    
    struct GST_Node *newnode = (struct GST_Node*)malloc(sizeof(struct GST_Node));
    newnode->name = strdup(name);
    newnode->type = type;
    newnode->size = size;
    newnode->paramlist = paramlist; 
    newnode->tuptype = tuptype;
    
    /* Calculate memory required: standard size * tuple field count (1 if primitive) */
    int mem_required = (tuptype != NULL) ? (size * tuptype->size) : size;
    
    if (paramlist != NULL || (size == 0 && paramlist == NULL)) {
        newnode->flabel = flabel_count++;
        newnode->binding = -1;
    } else {
        newnode->flabel = -1;
        newnode->binding = mem_address;
        mem_address += mem_required;
    }
    
    newnode->next = head;
    head = newnode;
}

void Install(char *name, int type, int rows, int cols) {
    int total = rows * cols;
    if (total == 0) total = 1;
    GInstall(name, type, total, NULL, NULL);
}

int getSP(void) {
    return mem_address - 1; 
}

void printSymbolTable(void) {
    struct GST_Node *temp = head;
    printf("\n========= GLOBAL SYMBOL TABLE =========\n");
    printf("%-10s %-10s %-10s %-10s %-10s\n", "NAME", "TYPE", "SIZE", "BINDING", "FLABEL");
    while (temp != NULL) {
        char *type_str = "UNKNOWN";
        if (temp->type == TYPE_INT) type_str = "INT";
        else if (temp->type == TYPE_STR) type_str = "STR";
        else if (temp->type == TYPE_INTPTR) type_str = "INT*";
        else if (temp->type == TYPE_STRPTR) type_str = "STR*";
        else if (temp->type == TYPE_TUPLE) type_str = "TUPLE";

        printf("%-10s %-10s %-10d %-10d %-10d\n", temp->name, type_str, temp->size, temp->binding, temp->flabel);
        temp = temp->next;
    }
    printf("=======================================\n\n");
}