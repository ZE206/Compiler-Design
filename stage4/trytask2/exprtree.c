#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprtree.h"
#include "y.tab.h"

struct tnode* createTree(int val, int type, char* varname, int nodetype, struct tnode *l, struct tnode *r) {
    struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    temp->nodetype = nodetype;
    temp->left = l;
    temp->right = r;
    temp->varname = varname ? strdup(varname) : NULL;
    
    if (nodetype == NODE_VAR) {
        struct GST_Node *g = Lookup(varname);
        if (g == NULL) {
            printf("Semantic Error: Variable '%s' is used without being declared.\n", varname);
            exit(1);
        }
        temp->Gentry = g;
        temp->type = g->type;
    } else {
        temp->Gentry = NULL;
        temp->type = type;
    }

    /* Type Checking */
    if (nodetype == NODE_OP) {
        if (l->type != TYPE_INT || r->type != TYPE_INT) {
            printf("Type Error: Arithmetic operators require Integer operands.\n"); exit(1);
        }
    } else if (nodetype == NODE_RELOP) {
        if (l->type != r->type) {
            printf("Type Error: Relational operators require matching operand types.\n"); exit(1);
        }
    } else if (nodetype == NODE_ASSIGN) {
        if (l->type != r->type) {
            printf("Type Error: Type mismatch in assignment.\n"); exit(1);
        }
    }
    return temp;
}

/* Loop control stacks */
static int loop_start_stack[100], loop_end_stack[100], loop_top = -1;

void pushLoop(int start, int end) { 
    loop_start_stack[++loop_top] = start;
    loop_end_stack[loop_top] = end; 
}

void popLoop(void) { 
    if (loop_top >= 0) loop_top--;
}

/* Register and Label generation */
static int reg_count = 0, label_count = 0;
int getReg(void) {
    if (reg_count < 20) return reg_count++;
    printf("Out of registers!\n");
    exit(1);
}

void freeReg(void) {
    if (reg_count > 0) reg_count--;
}

int getLabel(void) {
    return label_count++;
}

int codeGen(struct tnode *t) {
    extern FILE *target_file;
    if (t == NULL) return -1;

    switch(t->nodetype) {
        case NODE_NUM: {
            int reg=getReg();
            fprintf(target_file, "MOV R%d, %d\n",reg,t->val);
            return reg;
        }
        case NODE_STR_VAL: {
            int reg=getReg();
            fprintf(target_file, "MOV R%d, \"%s\"\n", reg, t->varname);
            return reg;
        }
        case NODE_VAR: {
            int reg=getReg();
            fprintf(target_file, "MOV R%d, [%d]\n", reg, t->Gentry->binding);
            return reg;
        }
        case NODE_ASSIGN: {
            int r = codeGen(t->right);
            fprintf(target_file, "MOV [%d], R%d\n", t->left->Gentry->binding, r);
            freeReg();
            return -1;
        }
        case NODE_READ: {
            int binding = t->left->Gentry->binding;
            int temp = getReg();
            
            fprintf(target_file, "MOV R%d, \"Read\"\n", temp);
            fprintf(target_file, "PUSH R%d\n", temp);      /* 1. Function Code */
            fprintf(target_file, "MOV R%d, -1\n", temp);
            fprintf(target_file, "PUSH R%d\n", temp);      /* 2. File Descriptor */
            fprintf(target_file, "MOV R%d, %d\n", temp, binding);
            fprintf(target_file, "PUSH R%d\n", temp);      /* 3. Buffer Address */
            fprintf(target_file, "PUSH R%d\n", temp);      /* 4. Unused */
            fprintf(target_file, "PUSH R%d\n", temp);      /* 5. Return Space */
            
            fprintf(target_file, "CALL 0\n");
            
            fprintf(target_file, "POP R%d\n", temp);
            fprintf(target_file, "POP R%d\n", temp);
            fprintf(target_file, "POP R%d\n", temp);
            fprintf(target_file, "POP R%d\n", temp);
            fprintf(target_file, "POP R%d\n", temp);
            
            freeReg(); /* temp */
            return -1;
        }
        case NODE_WRITE: {
            int val_reg = codeGen(t->left);
            int temp = getReg();
            
            fprintf(target_file, "MOV R%d, \"Write\"\n", temp);
            fprintf(target_file, "PUSH R%d\n", temp);      /* 1. Function Code */
            fprintf(target_file, "MOV R%d, -2\n", temp);
            fprintf(target_file, "PUSH R%d\n", temp);      /* 2. File Descriptor */
            fprintf(target_file, "PUSH R%d\n", val_reg);   /* 3. The Value */
            fprintf(target_file, "PUSH R%d\n", temp);      /* 4. Unused */
            fprintf(target_file, "PUSH R%d\n", temp);      /* 5. Return Space */
            
            fprintf(target_file, "CALL 0\n");
            
            fprintf(target_file, "POP R%d\n", temp);
            fprintf(target_file, "POP R%d\n", temp);
            fprintf(target_file, "POP R%d\n", temp);
            fprintf(target_file, "POP R%d\n", temp);
            fprintf(target_file, "POP R%d\n", temp);
            
            freeReg(); /* temp */
            freeReg(); /* val_reg */
            return -1;
        }
        case NODE_CONN: {
            codeGen(t->left);
            codeGen(t->right);
            return -1;
        }
        case NODE_WHILE: {
            int start = getLabel(), end = getLabel();
            pushLoop(start, end);
            fprintf(target_file, "L%d:\n", start);
            int cond = codeGen(t->left);
            fprintf(target_file, "JZ R%d, L%d\n", cond, end);
            freeReg();
            codeGen(t->right);
            fprintf(target_file, "JMP L%d\nL%d:\n", start, end);
            popLoop();
            return -1;
        }
        case NODE_DO_WHILE: {
            int start = getLabel(), end = getLabel();
            pushLoop(start, end);
            fprintf(target_file, "L%d:\n", start);
            codeGen(t->right);
            int cond = codeGen(t->left);
            fprintf(target_file, "JNZ R%d, L%d\n", cond, start);
            freeReg();
            fprintf(target_file, "L%d:\n", end);
            popLoop();
            return -1;
        }
        case NODE_REPEAT_UNTIL: {
            int start = getLabel(), end = getLabel();
            pushLoop(start, end);
            fprintf(target_file, "L%d:\n", start);
            codeGen(t->right);
            int cond = codeGen(t->left);
            fprintf(target_file, "JZ R%d, L%d\n", cond, start);
            freeReg();
            fprintf(target_file, "L%d:\n", end);
            popLoop();
            return -1;
        }
        case NODE_IF: {
            int end = getLabel();
            int cond = codeGen(t->left);
            fprintf(target_file, "JZ R%d, L%d\n", cond, end);
            freeReg();
            codeGen(t->right);
            fprintf(target_file, "L%d:\n", end);
            return -1;
        }
        case NODE_IF_ELSE: {
            int l_else = getLabel(), end = getLabel();
            int cond = codeGen(t->left);
            fprintf(target_file, "JZ R%d, L%d\n", cond, l_else);
            freeReg();
            codeGen(t->right->left); /* THEN block */
            fprintf(target_file, "JMP L%d\nL%d:\n", end, l_else);
            codeGen(t->right->right); /* ELSE block */
            fprintf(target_file, "L%d:\n", end);
            return -1;
        }
        case NODE_BREAK:
            if (loop_top >= 0) fprintf(target_file, "JMP L%d\n", loop_end_stack[loop_top]); return -1;
        case NODE_CONTINUE:
            if (loop_top >= 0) fprintf(target_file, "JMP L%d\n", loop_start_stack[loop_top]); return -1;
        case NODE_OP: {
            int l = codeGen(t->left), r = codeGen(t->right);
            if(t->val == '+') fprintf(target_file, "ADD R%d, R%d\n", l, r);
            if(t->val == '-') fprintf(target_file, "SUB R%d, R%d\n", l, r);
            if(t->val == '*') fprintf(target_file, "MUL R%d, R%d\n", l, r);
            if(t->val == '/') fprintf(target_file, "DIV R%d, R%d\n", l, r);
            freeReg(); return l;
        }
        case NODE_RELOP: {
            int l = codeGen(t->left), r = codeGen(t->right);
            if (t->val == LT) fprintf(target_file, "LT R%d, R%d\n", l, r);
            if (t->val == GT) fprintf(target_file, "GT R%d, R%d\n", l, r);
            if (t->val == LE) fprintf(target_file, "LE R%d, R%d\n", l, r);
            if (t->val == GE) fprintf(target_file, "GE R%d, R%d\n", l, r);
            if (t->val == EQ) fprintf(target_file, "EQ R%d, R%d\n", l, r);
            if (t->val == NE) fprintf(target_file, "NE R%d, R%d\n", l, r);
            freeReg(); return l;
        }
    }
    return -1;
}