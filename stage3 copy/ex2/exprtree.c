#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprtree.h"
#include "y.tab.h"

#define MAX_REG 20

int reg_count = 0;
int label_count = 0;
extern FILE *target_file;

int getReg(void) {
    if (reg_count < MAX_REG) {
        return reg_count++;
    }
    fprintf(stderr, "Out of registers\n");
    exit(1);
}

void freeReg(void) {
    if (reg_count > 0) {
        reg_count--;
    }
}

int getLabel(void) {
    return label_count++;
}

int getMemoryAddress(char var) {
    return 4096 + (var - 'a');
}

struct tnode* createTree(int val, int type, char* varname, int nodetype, 
                         struct tnode *l, struct tnode *m, struct tnode *r) {
    struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    temp->type = type;
    temp->nodetype = nodetype;
    if (varname != NULL) {
        temp->varname = strdup(varname);
    } else {
        temp->varname = NULL;
    }
    temp->left = l;
    temp->mid = m;
    temp->right = r;
    return temp;
}

int codeGen(struct tnode *t) {
    if (t == NULL) return -1;

    switch (t->nodetype) {
        case NODE_NUM: {
            int r = getReg();
            fprintf(target_file, "MOV R%d, %d\n", r, t->val);
            return r;
        }

        case NODE_VAR: {
            int r = getReg();
            int addr = getMemoryAddress(t->varname[0]);
            fprintf(target_file, "MOV R%d, [%d]\n", r, addr);
            return r;
        }

        case NODE_OP: {
            int l = codeGen(t->left);
            int r = codeGen(t->right);
            switch (t->val) {
                case '+': fprintf(target_file, "ADD R%d, R%d\n", l, r); break;
                case '-': fprintf(target_file, "SUB R%d, R%d\n", l, r); break;
                case '*': fprintf(target_file, "MUL R%d, R%d\n", l, r); break;
                case '/': fprintf(target_file, "DIV R%d, R%d\n", l, r); break;
            }
            freeReg();
            return l;
        }

        case NODE_RELOP: {
            int l = codeGen(t->left);
            int r = codeGen(t->right);
            switch (t->val) {
                case LT: fprintf(target_file, "LT R%d, R%d\n", l, r); break;
                case GT: fprintf(target_file, "GT R%d, R%d\n", l, r); break;
                case LE: fprintf(target_file, "LE R%d, R%d\n", l, r); break;
                case GE: fprintf(target_file, "GE R%d, R%d\n", l, r); break;
                case EQ: fprintf(target_file, "EQ R%d, R%d\n", l, r); break;
                case NE: fprintf(target_file, "NE R%d, R%d\n", l, r); break;
            }
            freeReg();
            return l;
        }

        case NODE_ASSIGN: {
            int r = codeGen(t->right);
            int addr = getMemoryAddress(t->left->varname[0]);
            fprintf(target_file, "MOV [%d], R%d\n", addr, r);
            freeReg();
            return -1;
        }

        case NODE_IF: {
            int l1 = getLabel();
            int condReg = codeGen(t->left);
            fprintf(target_file, "JZ R%d, L%d\n", condReg, l1);
            freeReg();

            codeGen(t->mid); /* THEN body */
            fprintf(target_file, "L%d:\n", l1);
            return -1;
        }

        case NODE_IF_ELSE: {
            int l_else = getLabel();
            int l_exit = getLabel();
            int condReg = codeGen(t->left);
            fprintf(target_file, "JZ R%d, L%d\n", condReg, l_else);
            freeReg();

            codeGen(t->mid);   /* THEN body */
            fprintf(target_file, "JMP L%d\n", l_exit);

            fprintf(target_file, "L%d:\n", l_else);
            codeGen(t->right); /* ELSE body */

            fprintf(target_file, "L%d:\n", l_exit);
            return -1;
        }

        case NODE_WHILE: {
            int l_start = getLabel();
            int l_exit  = getLabel();

            fprintf(target_file, "L%d:\n", l_start);
            int condReg = codeGen(t->left);
            fprintf(target_file, "JZ R%d, L%d\n", condReg, l_exit);
            freeReg();

            codeGen(t->right); /* While body */
            fprintf(target_file, "JMP L%d\n", l_start);

            fprintf(target_file, "L%d:\n", l_exit);
            return -1;
        }

        case NODE_READ: {
            int addr = getMemoryAddress(t->left->varname[0]);
            int r = getReg();
            fprintf(target_file, "PUSH R%d\nPUSH R%d\n", r, r);
            fprintf(target_file, "MOV R%d, \"Read\"\nPUSH R%d\n", r, r);
            fprintf(target_file, "MOV R%d, -1\nPUSH R%d\n", r, r);
            fprintf(target_file, "MOV R%d, %d\nPUSH R%d\n", r, addr);
            fprintf(target_file, "MOV R%d, 0\nPUSH R%d\nPUSH R%d\n", r, r, r);
            fprintf(target_file, "CALL 0\n");
            for (int i = 0; i < 7; i++) fprintf(target_file, "POP R%d\n", r);
            freeReg();
            return -1;
        }

        case NODE_WRITE: {
            int valReg = codeGen(t->left);
            int r = getReg();
            fprintf(target_file, "PUSH R%d\nPUSH R%d\n", r, r);
            fprintf(target_file, "MOV R%d, \"Write\"\nPUSH R%d\n", r, r);
            fprintf(target_file, "MOV R%d, -2\nPUSH R%d\n", r, r);
            fprintf(target_file, "PUSH R%d\n", valReg);
            fprintf(target_file, "MOV R%d, 0\nPUSH R%d\nPUSH R%d\n", r, r, r);
            fprintf(target_file, "CALL 0\n");
            for (int i = 0; i < 7; i++) fprintf(target_file, "POP R%d\n", r);
            freeReg();
            freeReg();
            return -1;
        }

        case NODE_CONN:
            codeGen(t->left);
            codeGen(t->right);
            return -1;
    }
    return -1;
}