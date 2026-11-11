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

struct tnode* createTree(int val, int type, char* varname, int nodetype, struct tnode* l, struct tnode *r) {
    if (nodetype == NODE_OP) {
        if (l->type != TYPE_INT || r->type != TYPE_INT) {
            fprintf(stderr, "Type Mismatch Error: Arithmetic operations require integer operands\n");
            exit(1);
        }
    }

    if (nodetype == NODE_RELOP) {
        if (l->type != TYPE_INT || r->type != TYPE_INT) {
            fprintf(stderr, "Type Mismatch Error: Relational comparisons require integer operands\n");
            exit(1);
        }
    }

    struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
    if (!temp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    temp->val = val;
    temp->type = type;
    temp->nodetype = nodetype;
    
    if (varname != NULL) {
        temp->varname = strdup(varname); 
    } else {
        temp->varname = NULL;
    }

    temp->left = l;
    temp->right = r;

    return temp;
}

int codeGen(struct tnode *t) {
    if (t == NULL) return -1;

    int reg;

    switch (t->nodetype) {
        case NODE_NUM:
            reg = getReg();
            fprintf(target_file, "MOV R%d, %d\n", reg, t->val);
            return reg;
        
        case NODE_VAR:
            reg = getReg();
            int addr = getMemoryAddress(t->varname[0]);
            fprintf(target_file, "MOV R%d, [%d]\n", reg, addr);
            return reg;
        
        case NODE_OP: {
            int leftReg = codeGen(t->left);
            int rightReg = codeGen(t->right);
            switch (t->val) {
                case '+': fprintf(target_file, "ADD R%d, R%d\n", leftReg, rightReg); break;
                case '-': fprintf(target_file, "SUB R%d, R%d\n", leftReg, rightReg); break;
                case '*': fprintf(target_file, "MUL R%d, R%d\n", leftReg, rightReg); break;
                case '/': fprintf(target_file, "DIV R%d, R%d\n", leftReg, rightReg); break;
            }
            freeReg();
            return leftReg;
        }

        case NODE_RELOP: {
            int leftReg = codeGen(t->left);
            int rightReg = codeGen(t->right);

            switch (t->val) {
                case LT: fprintf(target_file, "LT R%d, R%d\n", leftReg, rightReg); break;
                case GT: fprintf(target_file, "GT R%d, R%d\n", leftReg, rightReg); break;
                case LE: fprintf(target_file, "LE R%d, R%d\n", leftReg, rightReg); break;
                case GE: fprintf(target_file, "GE R%d, R%d\n", leftReg, rightReg); break;
                case EQ: fprintf(target_file, "EQ R%d, R%d\n", leftReg, rightReg); break;
                case NE: fprintf(target_file, "NE R%d, R%d\n", leftReg, rightReg); break;
            }
            freeReg();
            return leftReg;
        }
        
        case NODE_ASSIGN: {
            int rightReg = codeGen(t->right);
            int vAddr = getMemoryAddress(t->left->varname[0]);
            fprintf(target_file, "MOV [%d], R%d\n", vAddr, rightReg);
            freeReg();
            return -1;
        }

        case NODE_IF: {
            int l1 = getLabel();
            int condReg = codeGen(t->left);
            fprintf(target_file, "JZ R%d, L%d\n", condReg, l1);
            freeReg();

            codeGen(t->right); /* Execute THEN body */
            fprintf(target_file, "L%d:\n", l1);
            return -1;
        }

        case NODE_IF_ELSE: {
            int l1 = getLabel();
            int l2 = getLabel();
            int condReg = codeGen(t->left);
            fprintf(target_file, "JZ R%d, L%d\n", condReg, l1);
            freeReg();

            codeGen(t->right->left); /* THEN body */
            fprintf(target_file, "JMP L%d\n", l2);

            fprintf(target_file, "L%d:\n", l1);
            codeGen(t->right->right); /* ELSE body */

            fprintf(target_file, "L%d:\n", l2);
            return -1;
        }

        case NODE_WHILE: {
            int l1 = getLabel();
            int l2 = getLabel();

            fprintf(target_file, "L%d:\n", l1);
            int condReg = codeGen(t->left);
            fprintf(target_file, "JZ R%d, L%d\n", condReg, l2);
            freeReg();

            codeGen(t->right); /* Loop body */
            fprintf(target_file, "JMP L%d\n", l1);

            fprintf(target_file, "L%d:\n", l2);
            return -1;
        }

        case NODE_READ: {
            int rAddr = getMemoryAddress(t->left->varname[0]);
            reg = getReg();

            /* Push 2 dummy registers to align with library SP-7 offset */
            fprintf(target_file, "PUSH R%d\n", reg);
            fprintf(target_file, "PUSH R%d\n", reg);

            /* 5 System Call Slots */
            fprintf(target_file, "MOV R%d, \"Read\"\n", reg);
            fprintf(target_file, "PUSH R%d\n", reg);
            fprintf(target_file, "MOV R%d, -1\n", reg);
            fprintf(target_file, "PUSH R%d\n", reg);
            fprintf(target_file, "MOV R%d, %d\n", reg, rAddr);
            fprintf(target_file, "PUSH R%d\n", reg);
            fprintf(target_file, "MOV R%d, 0\n", reg);
            fprintf(target_file, "PUSH R%d\n", reg);
            fprintf(target_file, "PUSH R%d\n", reg);

            fprintf(target_file, "CALL 0\n");

            /* Pop all 7 slots */
            for (int i = 0; i < 7; i++) {
                fprintf(target_file, "POP R%d\n", reg);
            }
            freeReg();
            return -1;
        }

        case NODE_WRITE: {
            int valReg = codeGen(t->left);
            reg = getReg();

            /* Push 2 dummy registers */
            fprintf(target_file, "PUSH R%d\n", reg);
            fprintf(target_file, "PUSH R%d\n", reg);

            /* 5 System Call Slots */
            fprintf(target_file, "MOV R%d, \"Write\"\n", reg);
            fprintf(target_file, "PUSH R%d\n", reg);
            fprintf(target_file, "MOV R%d, -2\n", reg);
            fprintf(target_file, "PUSH R%d\n", reg);
            fprintf(target_file, "PUSH R%d\n", valReg);
            fprintf(target_file, "MOV R%d, 0\n", reg);
            fprintf(target_file, "PUSH R%d\n", reg);
            fprintf(target_file, "PUSH R%d\n", reg);

            fprintf(target_file, "CALL 0\n");

            /* Pop all 7 slots */
            for (int i = 0; i < 7; i++) {
                fprintf(target_file, "POP R%d\n", reg);
            }
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