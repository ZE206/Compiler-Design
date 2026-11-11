#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprtree.h"
#include "y.tab.h"

extern FILE *target_file;

struct tnode* createTree(int val, int type, char* varname, int nodetype, struct tnode *l, struct tnode *r) {
    struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    temp->nodetype = nodetype;
    temp->left = l;
    temp->right = r;
    temp->varname = varname ? strdup(varname) : NULL;
    
    /* Initialize pointers to prevent random Segmentation Faults */
    temp->Gentry = NULL;
    temp->Lentry = NULL;
    temp->tuptype = NULL; /* NEW: Tuple Schema Pointer */
    
    if(nodetype == NODE_VAR) {
        struct LST_Node *loc = LLookup(varname);
        if(loc != NULL){
            temp->Lentry = loc;
            temp->type = loc->type;
            temp->tuptype = loc->tuptype; /* NEW: Link local tuple schema */
        }
        else{
            struct GST_Node *g = GLookup(varname); 
            if (g == NULL) {
                printf("Semantic Error: Variable '%s' is used without being declared.\n", varname);
                exit(1);
            }
            temp->Gentry = g;
            temp->type = g->type;
            temp->tuptype = g->tuptype; /* NEW: Link global tuple schema */
        }
    } else {
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
        /* NEW: Verify tuple schemas match during block assignment */
        if (l->type == TYPE_TUPLE && l->tuptype != r->tuptype) {
            printf("Type Error: Tuple schema mismatch in assignment.\n"); exit(1);
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

int codeGenAddress(struct tnode *t) {
    if (t->nodetype == NODE_VAR) {
        if (t->Lentry != NULL) {
            int r = getReg();
            fprintf(target_file, "MOV R%d, BP\n", r);
            
            int offsetReg = getReg();
            fprintf(target_file, "MOV R%d, %d\n", offsetReg, t->Lentry->binding);
            fprintf(target_file, "ADD R%d, R%d\n", r, offsetReg);
            freeReg();
            
            return r;
        } 
        else if (t->Gentry != NULL) {
            int r = getReg();
            fprintf(target_file, "MOV R%d, %d\n", r, t->Gentry->binding);
            return r;
        }
    }
    
    /* NEW: Calculate address of a specific field inside a tuple */
    if (t->nodetype == NODE_FIELD) {
        int base_addr_reg = codeGenAddress(t->left); /* Get address of the tuple base */
        
        int offset_reg = getReg();
        fprintf(target_file, "MOV R%d, %d\n", offset_reg, t->val); /* Field offset is stored in val */
        fprintf(target_file, "ADD R%d, R%d\n", base_addr_reg, offset_reg);
        freeReg();
        
        return base_addr_reg;
    }
    
    if (t->nodetype == NODE_ARRAY) {
        int reg = getReg(); 
        int index_reg = codeGen(t->right);
        
        int base_addr = t->left->Gentry->binding;
        fprintf(target_file, "MOV R%d, %d\n", reg, base_addr);
        fprintf(target_file, "ADD R%d, R%d\n", reg, index_reg);
        
        freeReg(); 
        return reg;
    }
    if (t->nodetype == NODE_ARRAY_2D) {
        int reg = getReg(); 
        
        int row_reg = codeGen(t->right->left);
        int col_reg = codeGen(t->right->right);
        
        int base_addr = t->left->Gentry->binding;
        int num_cols = t->left->Gentry->cols;
        
        fprintf(target_file, "MUL R%d, %d\n", row_reg, num_cols);
        fprintf(target_file, "ADD R%d, R%d\n", row_reg, col_reg);
        
        fprintf(target_file, "MOV R%d, %d\n", reg, base_addr);
        fprintf(target_file, "ADD R%d, R%d\n", reg, row_reg);
        
        freeReg(); 
        freeReg(); 
        return reg;
    }
    if (t->nodetype == NODE_PTR_DEREF) {
        return codeGen(t->left);
    }
    printf("Compiler Error: Invalid lvalue for assignment/read.\n");
    exit(1);
}

int codeGen(struct tnode *t) {
    if (t == NULL) return -1;

    switch(t->nodetype) {
        case NODE_NUM: {
            int reg = getReg();
            fprintf(target_file, "MOV R%d, %d\n", reg, t->val);
            return reg;
        }
        case NODE_STR_VAL: {
            int reg = getReg();
            fprintf(target_file, "MOV R%d, \"%s\"\n", reg, t->varname);
            return reg;
        }
        
        /* 1. Standard Variables, Arrays, and Tuple Fields (RHS) */
        case NODE_VAR:
        case NODE_ARRAY:
        case NODE_ARRAY_2D: 
        case NODE_FIELD: { /* NEW: Support for fetching a.name */
            int addr_reg = codeGenAddress(t);
            
            /* If we are evaluating an ENTIRE tuple (e.g. assigning a to b), we want its base ADDRESS. 
               If we are evaluating a primitive field/var, we want its VALUE. */
            if (t->type != TYPE_TUPLE) {
                fprintf(target_file, "MOV R%d, [R%d]\n", addr_reg, addr_reg);
            }
            return addr_reg;
        }
        
        /* 2. Pointer Dereference (RHS: e.g., temp = *p) */
        case NODE_PTR_DEREF: {
            int ptr_reg = codeGen(t->left); 
            fprintf(target_file, "MOV R%d, [R%d]\n", ptr_reg, ptr_reg);
            return ptr_reg;
        }
        
        /* 3. Address-Of (e.g., p = &x) */
        case NODE_PTR_ADDR: {
            return codeGenAddress(t->left);
        }
        
        /* 4. Assignment (LHS: e.g., x = 5 OR *p = 5 OR a.name = "John" OR a = b) */
        case NODE_ASSIGN: {
            /* NEW: Block memory copying for Tuple-to-Tuple assignment */
            if (t->left->type == TYPE_TUPLE) {
                int l_addr = codeGenAddress(t->left);
                int r_addr = codeGenAddress(t->right); /* Right evaluates to base address due to TYPE_TUPLE check above */
                int size = t->left->tuptype->size;
                
                int temp1 = getReg();
                int temp2 = getReg();
                
                /* Unroll the loop to copy every field sequentially */
                for(int i = 0; i < size; i++) {
                    fprintf(target_file, "MOV R%d, R%d\n", temp1, l_addr);
                    fprintf(target_file, "ADD R%d, %d\n", temp1, i);
                    
                    fprintf(target_file, "MOV R%d, R%d\n", temp2, r_addr);
                    fprintf(target_file, "ADD R%d, %d\n", temp2, i);
                    fprintf(target_file, "MOV R%d, [R%d]\n", temp2, temp2); /* Read from source */
                    
                    fprintf(target_file, "MOV [R%d], R%d\n", temp1, temp2); /* Write to destination */
                }
                
                freeReg(); freeReg();
                freeReg(); freeReg(); /* Free l_addr and r_addr */
                return -1;
            } 
            
            /* Standard Assignment for primitives and fields */
            int r = codeGen(t->right);
            int addr_reg;
            
            if (t->left->nodetype == NODE_PTR_DEREF) {
                addr_reg = codeGen(t->left->left); 
            } else {
                addr_reg = codeGenAddress(t->left); 
            }
            
            fprintf(target_file, "MOV [R%d], R%d\n", addr_reg, r);
            
            freeReg(); 
            freeReg(); 
            return -1;
        }

        /* 5. Read (LHS: e.g., read(x) OR read(*p) OR read(a.name)) */
        case NODE_READ: {
            int addr_reg;
            
            if (t->left->nodetype == NODE_PTR_DEREF) {
                addr_reg = codeGen(t->left->left);
            } else {
                addr_reg = codeGenAddress(t->left); 
            }
            
            int temp = getReg();
            
            fprintf(target_file, "MOV R%d, \"Read\"\n", temp);
            fprintf(target_file, "PUSH R%d\n", temp);      
            fprintf(target_file, "MOV R%d, -1\n", temp);
            fprintf(target_file, "PUSH R%d\n", temp);      
            fprintf(target_file, "PUSH R%d\n", addr_reg);  
            fprintf(target_file, "PUSH R%d\n", temp);      
            fprintf(target_file, "PUSH R%d\n", temp);      
            
            fprintf(target_file, "CALL 0\n");
            
            fprintf(target_file, "POP R%d\n", temp);
            fprintf(target_file, "POP R%d\n", temp);
            fprintf(target_file, "POP R%d\n", temp);
            fprintf(target_file, "POP R%d\n", temp);
            fprintf(target_file, "POP R%d\n", temp);
            
            freeReg(); 
            freeReg(); 
            return -1;
        }
        
        case NODE_WRITE: {
            int val_reg = codeGen(t->left);
            int temp = getReg();
            
            fprintf(target_file, "MOV R%d, \"Write\"\n", temp);
            fprintf(target_file, "PUSH R%d\n", temp);      
            fprintf(target_file, "MOV R%d, -2\n", temp);
            fprintf(target_file, "PUSH R%d\n", temp);      
            fprintf(target_file, "PUSH R%d\n", val_reg);   
            fprintf(target_file, "PUSH R%d\n", temp);      
            fprintf(target_file, "PUSH R%d\n", temp);      
            
            fprintf(target_file, "CALL 0\n");
            
            fprintf(target_file, "POP R%d\n", temp);
            fprintf(target_file, "POP R%d\n", temp);
            fprintf(target_file, "POP R%d\n", temp);
            fprintf(target_file, "POP R%d\n", temp);
            fprintf(target_file, "POP R%d\n", temp);
            
            freeReg(); 
            freeReg(); 
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
            codeGen(t->right->left); 
            fprintf(target_file, "JMP L%d\nL%d:\n", end, l_else);
            codeGen(t->right->right); 
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
        
        case NODE_RET: {
            int res_reg = codeGen(t->left);
            int temp_reg = getReg();
            
            fprintf(target_file, "MOV R%d, BP\n", temp_reg);
            fprintf(target_file, "SUB R%d, 2\n", temp_reg);
            fprintf(target_file, "MOV [R%d], R%d\n", temp_reg, res_reg);
            
            freeReg(); 
            freeReg(); 
            
            int discard_reg = getReg();
            extern int local_binding;
            int num_locals = local_binding - 1;
            for(int i = 0; i < num_locals; i++) {
                fprintf(target_file, "POP R%d\n", discard_reg);
            }
            freeReg();
            
            fprintf(target_file, "POP BP\n");
            fprintf(target_file, "RET\n");
            return -1;
        }

        case NODE_FUNC_CALL: {
            struct GST_Node *g = t->left->Gentry;
            int active_regs = getReg() - 1; 
            freeReg(); 
            
            for (int i = 0; i <= active_regs; i++) {
                fprintf(target_file, "PUSH R%d\n", i);
            }
            
            struct tnode *arg = t->right;
            int arg_count = 0;
            while (arg != NULL) {
                int reg;
                if (arg->nodetype == NODE_CONN) {
                    reg = codeGen(arg->left);
                } else {
                    reg = codeGen(arg); 
                }
                fprintf(target_file, "PUSH R%d\n", reg);
                freeReg();
                arg = arg->right;
                arg_count++;
            }
            
            fprintf(target_file, "PUSH R0\n"); 
            fprintf(target_file, "CALL F%d\n", g->flabel);
            
            int res_reg = getReg();
            fprintf(target_file, "POP R%d\n", res_reg);
            
            int discard_reg = getReg();
            for (int i = 0; i < arg_count; i++) {
                fprintf(target_file, "POP R%d\n", discard_reg);
            }
            freeReg();
            
            for (int i = active_regs; i >= 0; i--) {
                fprintf(target_file, "POP R%d\n", i);
            }
            return res_reg;
        }
        
    }
    return -1;
}