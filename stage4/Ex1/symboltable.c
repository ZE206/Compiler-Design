#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboltable.h"

static struct GST_Node *head = NULL;
static int mem_address = 4096; /* Starting static memory address for XSM */

struct GST_Node* Lookup(char *name) {
    struct GST_Node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

void Install(char *name, int type, int rows, int cols) {
    if (Lookup(name) != NULL) {
        printf("Semantic Error: Variable '%s' is already declared.\n", name);
        exit(1);
    }
    struct GST_Node *newnode = (struct GST_Node*)malloc(sizeof(struct GST_Node));
    newnode->name = strdup(name);
    newnode->type = type;
    newnode->size = rows;
    newnode->cols = cols;
    int total_size = rows * cols; /* Total size for 2D arrays */
    if (total_size == 0) total_size = 1;
    newnode->binding = mem_address;
    mem_address += total_size;
    
    newnode->next = head;
    head = newnode;
}

int getSP(void) {
    return mem_address - 1; /* Return the last allocated memory address for SP initialization */
}

void printSymbolTable(void) {
    struct GST_Node *temp = head;
    printf("\n========= GLOBAL SYMBOL TABLE =========\n");
    printf("%-10s %-10s %-10s %-10s\n", "NAME", "TYPE", "SIZE", "BINDING");
    while (temp != NULL) {
        printf("%-10s %-10s %-10d %-10d\n", temp->name, temp->type == TYPE_INT ? "INT" : "STR", temp->size, temp->binding);
        temp = temp->next;
    }
    printf("=======================================\n\n");
}