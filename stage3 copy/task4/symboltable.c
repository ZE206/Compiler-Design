#include <stdio.h>
#include <string.h>
#include "symboltable.h"

struct GST_Node* GSymbolTable=NULL;
static int mem_address = 4096;

struct GST_Node* Lookup(char* name){
    struct GST_Node* currNode=GSymbolTable; // dont know how to refer to the first entry if table
    if(currNode==NULL){
        return NULL;
    }
    while(currNode->next!=NULL){
        if(strcmp(name, currNode->name)==0){
            return currNode;
        }
        currNode=currNode->next;
    }
    return NULL;
}

struct GST_Node* GInstall(char* name,  int type,int size){

    if(Lookup(name)!=NULL){
        fprintf(stderr, "Variable already exists");
        exit(1);
    }

    struct GST_Node* newNode=(struct GST_Node*)malloc(sizeof(struct GST_Node));
    newNode->name=strdup(name);
    newNode->type=type;
    newNode->size=size;
    newNode->binding=mem_address;
    mem_address+=size;

    newNode->next=GSymbolTable;
    GSymbolTable=newNode;
}

int getSP(void){
    return mem_address-1;
}
void printSymbolTable(void){
    struct GST_Node* temp=GSymbolTable;

    printf("\n============= GLOBAL SYMBOL TABLE ===============");

    printf("%-10s %-10s %-10s %-10s\n", "NAME", "TYPE", "SIZE", "BINDING");
    while (temp != NULL) {
        printf("%-10s %-10s %-10d %-10d\n", temp->name, temp->type == TYPE_INT ? "INT" : "STR", temp->size, temp->binding);
        temp = temp->next;
    }

    printf("\n==================================================");
}

