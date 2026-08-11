#include "exprtree.h"

#define MAX_REG 20

int reg_count = 0;

int getReg(void){
    if (reg_count < MAX_REG) {
        return reg_count++;
    } else {
        fprintf(stderr, "Out of registers\n");
        exit(1);
    }
}

void freeReg(void){
    if (reg_count > 0) {
        reg_count--;
    } else {
        fprintf(stderr, "No registers to free\n");
        exit(1);
    }
}

int getMemoryAddress(char var){
    /* Single lowercase letter variables mapped starting from address 4096 */
    return 4096 + (var - 'a');
}

extern FILE *target_file;

int codeGen(struct tnode *t){
    if (t == NULL) {
        return -1;
    }

    int reg;
    switch(t->type){
        case NODE_NUM:
            reg = getReg();
            fprintf(target_file, "MOV R%d, %d\n", reg, t->val);
            return reg;

        case NODE_VAR: {
            if (t->varname == NULL) {
                fprintf(stderr, "Error: NODE_VAR has NULL varname\n");
                exit(1);
            }
            reg = getReg();
            int addr = getMemoryAddress(t->varname[0]);
            fprintf(target_file, "MOV R%d, [%d]\n", reg, addr);
            return reg;
        }

        case NODE_OP: {
            int leftReg = codeGen(t->left);
            int rightReg = codeGen(t->right);
            switch(t->val){
                case '+':
                    fprintf(target_file, "ADD R%d, R%d\n", leftReg, rightReg);
                    break;
                case '-':
                    fprintf(target_file, "SUB R%d, R%d\n", leftReg, rightReg);
                    break;
                case '*':
                    fprintf(target_file, "MUL R%d, R%d\n", leftReg, rightReg);
                    break;
                case '/':
                    fprintf(target_file, "DIV R%d, R%d\n", leftReg, rightReg);
                    break;
                default:
                    fprintf(stderr, "Unknown operator: %c\n", t->val);
                    exit(1);
            }
            freeReg(); /* Free right register */
            return leftReg; /* Return register containing result */
        }

        case NODE_ASSIGN: {
            if (t->left == NULL || t->left->varname == NULL) {
                fprintf(stderr, "Error: Invalid target variable in ASSIGN\n");
                exit(1);
            }
            int rightReg = codeGen(t->right);
            int addr = getMemoryAddress(t->left->varname[0]);
            fprintf(target_file, "MOV [%d], R%d\n", addr, rightReg);
            freeReg();
            return -1;
        }

        case NODE_READ: {
            if (t->left == NULL || t->left->varname == NULL) {
                fprintf(stderr, "Error: Invalid variable in READ\n");
                exit(1);
            }

            int addr = getMemoryAddress(t->left->varname[0]);
            reg = getReg();

            /* Slot 1: "Read" */
            fprintf(target_file, "MOV R%d, \"Read\"\n", reg);
            fprintf(target_file, "PUSH R%d\n", reg);

            /* Slot 2: -1 (Stdin) */
            fprintf(target_file, "MOV R%d, -1\n", reg);
            fprintf(target_file, "PUSH R%d\n", reg);

            /* Slot 3: Target Address */
            fprintf(target_file, "MOV R%d, %d\n", reg, addr);
            fprintf(target_file, "PUSH R%d\n", reg);

            /* Slot 4: 0 (Blank argument) */
            fprintf(target_file, "MOV R%d, 0\n", reg);
            fprintf(target_file, "PUSH R%d\n", reg);

            /* Slot 5: Blank Return Value Space */
            fprintf(target_file, "PUSH R%d\n", reg);

            /* Call OS Interrupt */
            fprintf(target_file, "CALL 0\n");

            /* Clean up 5 slots from stack */
            fprintf(target_file, "POP R%d\n", reg);
            fprintf(target_file, "POP R%d\n", reg);
            fprintf(target_file, "POP R%d\n", reg);
            fprintf(target_file, "POP R%d\n", reg);
            fprintf(target_file, "POP R%d\n", reg);

            freeReg();
            return -1;
        }

        case NODE_WRITE: {
    int valReg = codeGen(t->left);
    int reg = getReg();

    /* Push 2 dummy registers to match library.lib's SP-7 offset */
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
    fprintf(target_file, "POP R%d\n", reg);
    fprintf(target_file, "POP R%d\n", reg);
    fprintf(target_file, "POP R%d\n", reg);
    fprintf(target_file, "POP R%d\n", reg);
    fprintf(target_file, "POP R%d\n", reg);
    fprintf(target_file, "POP R%d\n", reg);
    fprintf(target_file, "POP R%d\n", reg);

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

struct tnode* createTree(int val, int type, char* c, struct tnode *l, struct tnode *r){
    struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
    if (!temp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    temp->val = val;
    temp->type = type;
    if (c != NULL) {
        temp->varname = strdup(c); 
    } else {
        temp->varname = NULL;
    }
    temp->left = l;
    temp->right = r;
    return temp;
}