#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprtree.h"

int class_count = 0;
static int mem_address = 4096; // Global binding starts here, VTables will push it down
static int flabel_count = 0; 

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
    newField->ctype = CLookup(type_name); // Link to class table if it is an object
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
/* 2. CLASS TABLE IMPLEMENTATION (STAGE 7)                  */
/* ======================================================== */

struct Classtable *ClassTableHead = NULL;

struct Classtable* CInstall(char *name, char *parent_class_name) {
    if (CLookup(name) != NULL || TLookup(name) != NULL) {
        printf("Semantic Error: Class '%s' already defined.\n", name);
        exit(1);
    }
    
    struct Classtable *parentClass = NULL;
    if (parent_class_name != NULL) {
        parentClass = CLookup(parent_class_name);
        if (parentClass == NULL) {
            printf("Semantic Error: Parent class '%s' not found.\n", parent_class_name);
            exit(1);
        }
    }
    
    struct Classtable *newClass = (struct Classtable*)malloc(sizeof(struct Classtable));
    newClass->name = strdup(name);
    newClass->memberfield = NULL;
    newClass->vfuncptr = NULL;
    newClass->parentptr = parentClass; 
    newClass->class_index = class_count++;
    newClass->fieldcount = 0;
    newClass->methodcount = 0;
    newClass->next = NULL;

    /* STAGE 8: INHERITANCE DEEP COPY */
    if (parentClass != NULL) {
        newClass->fieldcount = parentClass->fieldcount;
        newClass->methodcount = parentClass->methodcount;
        
        // Deep copy fields
        struct Fieldlist *pField = parentClass->memberfield;
        struct Fieldlist *prevField = NULL;
        while (pField != NULL) {
            struct Fieldlist *f = (struct Fieldlist*)malloc(sizeof(struct Fieldlist));
            f->name = strdup(pField->name);
            f->fieldIndex = pField->fieldIndex;
            f->type = pField->type;
            f->ctype = pField->ctype;
            f->next = NULL;
            
            if (newClass->memberfield == NULL) newClass->memberfield = f;
            else prevField->next = f;
            
            prevField = f;
            pField = pField->next;
        }
        
        // Deep copy methods
        struct Memberfunclist *pMethod = parentClass->vfuncptr;
        struct Memberfunclist *prevMethod = NULL;
        while (pMethod != NULL) {
            struct Memberfunclist *m = (struct Memberfunclist*)malloc(sizeof(struct Memberfunclist));
            m->name = strdup(pMethod->name);
            m->type = pMethod->type;
            m->paramlist = pMethod->paramlist; // Pointers to types are safe to share
            m->funcposition = pMethod->funcposition;
            m->flabel = pMethod->flabel; // Keep parent's label (overrides will patch this later)
            m->next = NULL;
            
            if (newClass->vfuncptr == NULL) newClass->vfuncptr = m;
            else prevMethod->next = m;
            
            prevMethod = m;
            pMethod = pMethod->next;
        }
    }

    if (ClassTableHead == NULL) {
        ClassTableHead = newClass;
    } else {
        struct Classtable *temp = ClassTableHead;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newClass;
    }
    
    mem_address += 8; 
    TInstall(name, 2, NULL); 
    
    return newClass;
}

struct Classtable* CLookup(char *name) {
    struct Classtable *temp = ClassTableHead;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

void ClassFInstall(struct Classtable *cptr, struct Typetable *type, char *name) {
    if (ClassFLookup(cptr, name) != NULL) {
        printf("Semantic Error: Field '%s' already exists in class '%s'.\n", name, cptr->name);
        exit(1);
    }
    if (cptr->fieldcount >= 8) {
        printf("Semantic Error: Class '%s' exceeds the 8-field limit.\n", cptr->name);
        exit(1);
    }

    struct Fieldlist *newField = (struct Fieldlist*)malloc(sizeof(struct Fieldlist));
    newField->name = strdup(name);
    newField->fieldIndex = cptr->fieldcount++;
    newField->type = type;
    newField->ctype = CLookup(type->name); // Set ctype if the field is another object
    newField->next = NULL;

    if (cptr->memberfield == NULL) {
        cptr->memberfield = newField;
    } else {
        struct Fieldlist *temp = cptr->memberfield;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newField;
    }
}

int checkParams(struct ParamNode *p1, struct ParamNode *p2) {
    while (p1 != NULL && p2 != NULL) {
        if (p1->type != p2->type || strcmp(p1->name, p2->name) != 0) return 0; // Mismatch
        p1 = p1->next;
        p2 = p2->next;
    }
    return (p1 == NULL && p2 == NULL); // Both must end at the same time
}

void ClassMInstall(struct Classtable *cptr, char *name, struct Typetable *type, struct ParamNode *paramlist) {
    struct Memberfunclist *existing = ClassMLookup(cptr, name);
    
    /* STAGE 8 OVERRIDE: If method exists from parent, patch the flabel */
    if (existing != NULL) {
        if (existing->type != type) {
            printf("Semantic Error: Return type mismatch overriding method '%s'.\n", name);
            exit(1);
        }
        if (!checkParams(existing->paramlist, paramlist)) {
            printf("Semantic Error: Parameter signature mismatch overriding method '%s'.\n", name);
            exit(1);
        }
        existing->flabel = flabel_count++; 
        
        /* FREE the newly passed paramlist since we are keeping the parent's list structure */
        struct ParamNode *temp;
        while(paramlist != NULL) {
            temp = paramlist;
            paramlist = paramlist->next;
            free(temp->name);
            free(temp);
        }
        return; 
    }
    
    if (cptr->methodcount >= 8) {
        printf("Semantic Error: Class '%s' exceeds the 8-method limit.\n", cptr->name);
        exit(1);
    }

    struct Memberfunclist *newMethod = (struct Memberfunclist*)malloc(sizeof(struct Memberfunclist));
    newMethod->name = strdup(name);
    newMethod->type = type;
    newMethod->paramlist = paramlist;
    newMethod->funcposition = cptr->methodcount++;
    newMethod->flabel = flabel_count++;
    newMethod->next = NULL;

    if (cptr->vfuncptr == NULL) {
        cptr->vfuncptr = newMethod;
    } else {
        struct Memberfunclist *temp = cptr->vfuncptr;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newMethod;
    }
}

struct Fieldlist* ClassFLookup(struct Classtable *cptr, char *name) {
    if (cptr == NULL) return NULL;
    struct Fieldlist *temp = cptr->memberfield;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

struct Memberfunclist* ClassMLookup(struct Classtable *cptr, char *name) {
    if (cptr == NULL) return NULL;
    struct Memberfunclist *temp = cptr->vfuncptr;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

/* ======================================================== */
/* 3. GLOBAL & LOCAL SYMBOL TABLES                          */
/* ======================================================== */

static struct GST_Node *head = NULL;
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
    temp->ctype = (type != NULL) ? CLookup(type->name) : NULL;
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

void GInstall(char *name, struct Typetable *type, int size, struct ParamNode *paramlist) {
    if (GLookup(name) != NULL) {
        printf("Semantic Error: Identifier '%s' is already declared.\n", name);
        exit(1);
    }
    
    struct GST_Node *newnode = (struct GST_Node*)malloc(sizeof(struct GST_Node));
    newnode->name = strdup(name);
    newnode->type = type;
    newnode->ctype = (type != NULL) ? CLookup(type->name) : NULL;
    newnode->paramlist = paramlist; 
    
    int actual_size = size;
    // Objects require 2 words per instance (Data Ptr + VTable Ptr)
    if (newnode->ctype != NULL && size > 0) {
        actual_size = size * 2; 
    }
    
    newnode->size = actual_size;
    
    if (paramlist != NULL || (size == 0 && paramlist == NULL)) {
        newnode->flabel = flabel_count++;
        newnode->binding = -1;
    } else {
        newnode->flabel = -1;
        newnode->binding = mem_address;
        mem_address += actual_size;
    }
    
    newnode->next = head;
    head = newnode;
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