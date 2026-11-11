#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboltable.h"
static struct GST_Node *head=NULL;
static int mem_address=4096;

struct GST_Node* Lookup(char *name){
    struct GST_Node* temp=head;
    while(temp){
        if(strcmp(temp->name, name)==0){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

struct GST_Node* Install(char *name, int size, int type){
    
    if(Lookup(name)==NULL){
        printf("Semantic Eror: Variable %s is already declared.\n", name);
        exit(1);
    }

    struct GST_Node* newNode=(struct GST_Node*)malloc(sizeof(struct GST_Node));
    newNode->name=name;
    newNode->type=type;
    newNode->size=size;
    newNode->binding=mem_address;
    mem_address+=size;
    
    newNode->next=head;
    head=newNode;
}

int getSP(void){
    return mem_address-1;
}

void printSymbolTable(void){
    struct GST_Node* temp=head;
    printf("------- GLOBAL SYMBOL TABLE -------");
    printf("%-10s %-10s %-10s %-10s\n", "NAME", "TYPE", "SIZE", "BINDING");
    while(temp!=NULL){
        printf("%-10s %-10s %-10s %-10s", temp->name, temp->type==TYPE_INT ? "INT":"STR", temp->size, temp->binding);
        temp=temp->next;
    }
    
}