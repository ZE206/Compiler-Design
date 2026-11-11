#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprtree.h"
#include "y.tab.h"

extern FILE *target_file;

void initializeVTables(struct Classtable *Chead) {
    struct Classtable *tempClass = Chead;
    int current_vtable_addr = 4096;
    
    while (tempClass != NULL) {
        for (int i = 0; i < 8; i++) {
            int reg = getReg();
            fprintf(target_file, "MOV R%d, -1\n", reg);
            fprintf(target_file, "MOV [%d], R%d\n", current_vtable_addr + i, reg);
            freeReg();
        }
        
        struct Memberfunclist *mfunc = tempClass->vfuncptr;
        while (mfunc != NULL) {
            int method_addr = current_vtable_addr + mfunc->funcposition;
            int reg = getReg();
            fprintf(target_file, "MOV R%d, F%d\n", reg, mfunc->flabel);
            fprintf(target_file, "MOV [%d], R%d\n", method_addr, reg);
            freeReg();
            mfunc = mfunc->next;
        }
        
        tempClass->class_index = (current_vtable_addr - 4096) / 8;
        current_vtable_addr += 8;
        tempClass = tempClass->next;
    }
}

struct tnode* createTree(int val, struct Typetable *type, char* varname, int nodetype, struct tnode *l, struct tnode *r) {
    struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    temp->nodetype = nodetype;
    temp->left = l;
    temp->right = r;
    temp->varname = varname ? strdup(varname) : NULL;
    temp->Gentry = NULL;
    temp->Lentry = NULL;
    temp->Fentry = NULL;
    temp->ctype = NULL; /* CRITICAL: Must initialize to NULL */
    
    if (nodetype == NODE_VAR) {
        struct LST_Node *loc = LLookup(varname);
        if (loc != NULL) {
            temp->Lentry = loc;
            temp->type = loc->type;
            temp->ctype = loc->ctype;
        } else {
            struct GST_Node *g = GLookup(varname);
            if (g == NULL) {
                printf("Semantic Error: Variable '%s' used without being declared.\n", varname);
                exit(1);
            }
            temp->Gentry = g;
            temp->type = g->type;
            temp->ctype = g->ctype;
        }
    } else {
        temp->type = type;
    }

    if (nodetype == NODE_OP) {
        if (l->type != TLookup("int") || r->type != TLookup("int")) {
            printf("Type Error: Arithmetic operators require integer operands.\n");
            exit(1);
        }
        temp->type = TLookup("int");
    } 
    else if (nodetype == NODE_RELOP) {
        if (l->type != r->type) {
            int l_udt = (l->type != TLookup("int") && l->type != TLookup("str") && l->type != TLookup("boolean"));
            int r_udt = (r->type != TLookup("int") && r->type != TLookup("str") && r->type != TLookup("boolean"));
            if (!((l_udt && r->type == TLookup("null")) || (r_udt && l->type == TLookup("null")))) {
                printf("Type Error: Relational operators require matching operand types.\n");
                exit(1);
            }
        }
        temp->type = TLookup("boolean");
    } 
    else if (nodetype == NODE_ASSIGN) {
        int l_udt = (l->type != TLookup("int") && l->type != TLookup("str") && l->type != TLookup("boolean"));
        if (l->type != r->type) {
            if (!(l_udt && (r->type == TLookup("null") || r->type == TLookup("void")))) {
                printf("Type Error: Type mismatch in assignment between '%s' and '%s'.\n", 
                       l->type ? l->type->name : "unknown", 
                       r->type ? r->type->name : "unknown");
                exit(1);
            }
        }
    }
    return temp;
}

static int loop_start_stack[100], loop_end_stack[100], loop_top = -1;

void pushLoop(int start, int end) { 
    loop_start_stack[++loop_top] = start;
    loop_end_stack[loop_top] = end; 
}

void popLoop(void) { 
    if (loop_top >= 0) loop_top--;
}

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
    if (t->nodetype == NODE_SELF) {
        struct LST_Node *l = t->Lentry ? t->Lentry : LLookup("self");
        int r = getReg();
        fprintf(target_file, "MOV R%d, BP\n", r);
        fprintf(target_file, "ADD R%d, %d\n", r, l->binding);
        return r;
    }
    if (t->nodetype == NODE_VAR) {
        if (t->Lentry != NULL) {
            int r = getReg();
            fprintf(target_file, "MOV R%d, BP\n", r);
            fprintf(target_file, "ADD R%d, %d\n", r, t->Lentry->binding);
            return r;
        } else if (t->Gentry != NULL) {
            int r = getReg();
            fprintf(target_file, "MOV R%d, %d\n", r, t->Gentry->binding);
            return r;
        }
    }
    
    if (t->nodetype == NODE_FIELD) {
        int base_reg = codeGen(t->left);
        fprintf(target_file, "ADD R%d, %d\n", base_reg, t->val);
        return base_reg;
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
    printf("Compiler Error: Invalid lvalue.\n");
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
        case NODE_NULL: {
            int reg = getReg();
            fprintf(target_file, "MOV R%d, 0\n", reg);
            return reg;
        }
        
        case NODE_VAR:
        case NODE_ARRAY:
        case NODE_ARRAY_2D:
        case NODE_FIELD:
        case NODE_SELF: {
            int addr_reg = codeGenAddress(t);
            fprintf(target_file, "MOV R%d, [R%d]\n", addr_reg, addr_reg);
            return addr_reg;
        }
        
        case NODE_PTR_DEREF: {
            int ptr_reg = codeGen(t->left);
            fprintf(target_file, "MOV R%d, [R%d]\n", ptr_reg, ptr_reg);
            return ptr_reg;
        }
        
        case NODE_PTR_ADDR: {
            return codeGenAddress(t->left);
        }
        
        case NODE_ASSIGN: {
            if (t->right->nodetype == NODE_NEW) {
                int obj_base_addr_reg = codeGenAddress(t->left);
                struct Classtable *c = t->right->left->ctype; 
                
                /* Save active registers before calling library.lib (which clobbers R1-R6) */
                int active_regs = reg_count - 1;
                for (int i = 0; i <= active_regs; i++) {
                    fprintf(target_file, "PUSH R%d\n", i);
                }

                int heap_reg = getReg();
                fprintf(target_file, "MOV R%d, \"Alloc\"\n", heap_reg);
                fprintf(target_file, "PUSH R%d\n", heap_reg);
                fprintf(target_file, "MOV R%d, 0\n", heap_reg);
                fprintf(target_file, "PUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\n", heap_reg, heap_reg, heap_reg, heap_reg);
                fprintf(target_file, "CALL 0\n");
                fprintf(target_file, "POP R%d\n", heap_reg);
                
                int discard = getReg();
                fprintf(target_file, "POP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n", discard, discard, discard, discard);
                freeReg();

                for (int i = active_regs; i >= 0; i--) {
                    fprintf(target_file, "POP R%d\n", i);
                }
                
                /* Word 1: Heap Pointer */
                fprintf(target_file, "MOV [R%d], R%d\n", obj_base_addr_reg, heap_reg);
                
                /* Word 2: VTable Pointer */
                int vtable_addr = 4096 + (c->class_index * 8);
                fprintf(target_file, "ADD R%d, 1\n", obj_base_addr_reg);
                fprintf(target_file, "MOV [R%d], %d\n", obj_base_addr_reg, vtable_addr);
                
                freeReg();
                freeReg();
                return -1; 
            }

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

        case NODE_OBJ_FUNC_CALL:
        case NODE_FIELD_FUNC_CALL: {
            int active_regs = reg_count - 1; 
            
            // 1. Push all caller active registers
            for (int i = 0; i <= active_regs; i++) {
                fprintf(target_file, "PUSH R%d\n", i);
            }
            
            // 2. Resolve object base address
            int obj_addr_reg = codeGenAddress(t->left); 
            int vtable_reg = getReg();

            // 3. Push Word 1 (Heap Ptr) and Word 2 (VTable Ptr) for 'self'
            fprintf(target_file, "MOV R%d, [R%d]\n", vtable_reg, obj_addr_reg);
            fprintf(target_file, "PUSH R%d\n", vtable_reg); // Word 1 (BP - N - 4)
            
            fprintf(target_file, "ADD R%d, 1\n", obj_addr_reg);
            fprintf(target_file, "MOV R%d, [R%d]\n", vtable_reg, obj_addr_reg);
            fprintf(target_file, "PUSH R%d\n", vtable_reg); // Word 2 (BP - N - 3)
            
            /* Free obj_addr_reg and vtable_reg BEFORE evaluating arguments (in case args contain nested method calls!) */
            freeReg();
            freeReg();
            
            // 4. Push explicit arguments
            struct tnode *arg = t->right;
            int arg_count = 0;
            while (arg != NULL) {
                int reg = (arg->nodetype == NODE_CONN) ? codeGen(arg->left) : codeGen(arg); 
                fprintf(target_file, "PUSH R%d\n", reg);
                freeReg();
                arg = arg->right;
                arg_count++;
            }
            
            // 5. Reserve Return Slot
            fprintf(target_file, "PUSH R0\n"); 
            
            // 6. Fetch VTable Ptr directly from stack (it is sitting at SP - arg_count - 1) and CALL
            int call_reg = getReg();
            fprintf(target_file, "MOV R%d, SP\n", call_reg);
            fprintf(target_file, "SUB R%d, %d\n", call_reg, arg_count + 1);
            fprintf(target_file, "MOV R%d, [R%d]\n", call_reg, call_reg); // VTable Base Address
            
            struct Memberfunclist *m = ClassMLookup(t->ctype, t->varname);
            fprintf(target_file, "ADD R%d, %d\n", call_reg, m->funcposition);
            fprintf(target_file, "MOV R%d, [R%d]\n", call_reg, call_reg); // F-label address
            
            fprintf(target_file, "CALL R%d\n", call_reg);
            freeReg();
            
            // 7. Retrieve Return Value
            int res_reg = getReg();
            fprintf(target_file, "POP R%d\n", res_reg);
            
            // 8. Pop Arguments + Implicit 'self' (2 words)
            int discard_reg = getReg();
            for (int i = 0; i < arg_count + 2; i++) {
                fprintf(target_file, "POP R%d\n", discard_reg);
            }
            freeReg();
            
            // 9. Restore caller active registers
            for (int i = active_regs; i >= 0; i--) {
                fprintf(target_file, "POP R%d\n", i);
            }
            return res_reg;
        }

        case NODE_INIT: {
            int active_regs = reg_count - 1;
            for (int i = 0; i <= active_regs; i++) fprintf(target_file, "PUSH R%d\n", i);

            int reg = getReg();
            fprintf(target_file, "MOV R%d, \"Ini\"\n", reg);
            fprintf(target_file, "PUSH R%d\n", reg);
            fprintf(target_file, "MOV R%d, 0\n", reg);
            fprintf(target_file, "PUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\n", reg, reg, reg, reg);
            fprintf(target_file, "CALL 0\n");
            fprintf(target_file, "POP R%d\n", reg);
            int temp = getReg();
            fprintf(target_file, "POP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n", temp, temp, temp, temp);
            freeReg(); 

            for (int i = active_regs; i >= 0; i--) fprintf(target_file, "POP R%d\n", i);
            return reg;
        }

        case NODE_ALLOC: {
            int active_regs = reg_count - 1;
            for (int i = 0; i <= active_regs; i++) fprintf(target_file, "PUSH R%d\n", i);

            int reg = getReg();
            fprintf(target_file, "MOV R%d, \"Alloc\"\n", reg);
            fprintf(target_file, "PUSH R%d\n", reg);
            fprintf(target_file, "MOV R%d, 0\n", reg);
            fprintf(target_file, "PUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\n", reg, reg, reg, reg);
            fprintf(target_file, "CALL 0\n");
            fprintf(target_file, "POP R%d\n", reg);
            int temp = getReg();
            fprintf(target_file, "POP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n", temp, temp, temp, temp);
            freeReg(); 

            for (int i = active_regs; i >= 0; i--) fprintf(target_file, "POP R%d\n", i);
            return reg;
        }

        case NODE_FREE: {
            int ptr_reg = codeGen(t->left);
            int active_regs = reg_count - 1;
            for (int i = 0; i <= active_regs; i++) fprintf(target_file, "PUSH R%d\n", i);

            int temp = getReg();
            fprintf(target_file, "MOV R%d, \"Free\"\n", temp);
            fprintf(target_file, "PUSH R%d\n", temp);
            fprintf(target_file, "PUSH R%d\n", ptr_reg);
            fprintf(target_file, "MOV R%d, 0\n", temp);
            fprintf(target_file, "PUSH R%d\nPUSH R%d\nPUSH R%d\n", temp, temp, temp);
            fprintf(target_file, "CALL 0\n");
            fprintf(target_file, "POP R%d\n", temp);
            int discard = getReg();
            fprintf(target_file, "POP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n", discard, discard, discard, discard);
            freeReg(); 
            freeReg(); 

            for (int i = active_regs; i >= 0; i--) fprintf(target_file, "POP R%d\n", i);
            freeReg(); 
            return -1;
        }

        case NODE_DELETE: {
            int obj_addr_reg = codeGenAddress(t->left);
            int ptr_reg = getReg();
            fprintf(target_file, "MOV R%d, [R%d]\n", ptr_reg, obj_addr_reg);
            
            int active_regs = reg_count - 1;
            for (int i = 0; i <= active_regs; i++) fprintf(target_file, "PUSH R%d\n", i);

            int temp = getReg();
            fprintf(target_file, "MOV R%d, \"Free\"\n", temp);
            fprintf(target_file, "PUSH R%d\n", temp);
            fprintf(target_file, "PUSH R%d\n", ptr_reg);
            fprintf(target_file, "MOV R%d, 0\n", temp);
            fprintf(target_file, "PUSH R%d\nPUSH R%d\nPUSH R%d\n", temp, temp, temp);
            fprintf(target_file, "CALL 0\n");
            fprintf(target_file, "POP R%d\n", temp);
            int discard = getReg();
            fprintf(target_file, "POP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n", discard, discard, discard, discard);
            freeReg(); 
            freeReg(); 

            for (int i = active_regs; i >= 0; i--) fprintf(target_file, "POP R%d\n", i);
            freeReg();
            freeReg();
            return -1;
        }

        case NODE_READ: {
            int addr_reg;
            if (t->left->nodetype == NODE_PTR_DEREF) {
                addr_reg = codeGen(t->left->left);
            } else {
                addr_reg = codeGenAddress(t->left); 
            }
            
            int active_regs = reg_count - 1;
            for (int i = 0; i <= active_regs; i++) fprintf(target_file, "PUSH R%d\n", i);

            int temp = getReg();
            fprintf(target_file, "MOV R%d, \"Read\"\n", temp);
            fprintf(target_file, "PUSH R%d\n", temp);      
            fprintf(target_file, "MOV R%d, -1\n", temp);
            fprintf(target_file, "PUSH R%d\n", temp);      
            fprintf(target_file, "PUSH R%d\n", addr_reg);  
            fprintf(target_file, "PUSH R%d\n", temp);      
            fprintf(target_file, "PUSH R%d\n", temp);      
            fprintf(target_file, "CALL 0\n");
            
            fprintf(target_file, "POP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n", 
                    temp, temp, temp, temp, temp);
            freeReg(); 

            for (int i = active_regs; i >= 0; i--) fprintf(target_file, "POP R%d\n", i);
            freeReg(); 
            return -1;
        }
        
        case NODE_WRITE: {
            int val_reg = codeGen(t->left);
            int active_regs = reg_count - 1;
            for (int i = 0; i <= active_regs; i++) fprintf(target_file, "PUSH R%d\n", i);

            int temp = getReg();
            fprintf(target_file, "MOV R%d, \"Write\"\n", temp);
            fprintf(target_file, "PUSH R%d\n", temp);      
            fprintf(target_file, "MOV R%d, -2\n", temp);
            fprintf(target_file, "PUSH R%d\n", temp);      
            fprintf(target_file, "PUSH R%d\n", val_reg);   
            fprintf(target_file, "PUSH R%d\n", temp);      
            fprintf(target_file, "PUSH R%d\n", temp);      
            fprintf(target_file, "CALL 0\n");
            
            fprintf(target_file, "POP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n", 
                    temp, temp, temp, temp, temp);
            freeReg(); 

            for (int i = active_regs; i >= 0; i--) fprintf(target_file, "POP R%d\n", i);
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
            if (loop_top >= 0) fprintf(target_file, "JMP L%d\n", loop_end_stack[loop_top]); 
            return -1;
        case NODE_CONTINUE:
            if (loop_top >= 0) fprintf(target_file, "JMP L%d\n", loop_start_stack[loop_top]); 
            return -1;
            
        case NODE_OP: {
            int l = codeGen(t->left), r = codeGen(t->right);
            if(t->val == '+') fprintf(target_file, "ADD R%d, R%d\n", l, r);
            if(t->val == '-') fprintf(target_file, "SUB R%d, R%d\n", l, r);
            if(t->val == '*') fprintf(target_file, "MUL R%d, R%d\n", l, r);
            if(t->val == '/') fprintf(target_file, "DIV R%d, R%d\n", l, r);
            freeReg(); 
            return l;
        }
        
        case NODE_RELOP: {
            int l = codeGen(t->left), r = codeGen(t->right);
            if (t->val == LT) fprintf(target_file, "LT R%d, R%d\n", l, r);
            if (t->val == GT) fprintf(target_file, "GT R%d, R%d\n", l, r);
            if (t->val == LE) fprintf(target_file, "LE R%d, R%d\n", l, r);
            if (t->val == GE) fprintf(target_file, "GE R%d, R%d\n", l, r);
            if (t->val == EQ) fprintf(target_file, "EQ R%d, R%d\n", l, r);
            if (t->val == NE) fprintf(target_file, "NE R%d, R%d\n", l, r);
            if (t->val == AND) {
                fprintf(target_file, "MUL R%d, R%d\n", l, r);
            }
            freeReg(); 
            return l;
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
            int active_regs = reg_count - 1; 
            
            for (int i = 0; i <= active_regs; i++) {
                fprintf(target_file, "PUSH R%d\n", i);
            }
            
            struct tnode *arg = t->right;
            int arg_words = 0;  

            while (arg != NULL) {
                struct tnode *actual_arg =
                    (arg->nodetype == NODE_CONN) ? arg->left : arg;

                /* Is this argument a class-type value? */
                if (actual_arg->type != NULL &&
                    CLookup(actual_arg->type->name) != NULL) {

                    /* Get the address of the two-word object variable */
                    int addr_reg = codeGenAddress(actual_arg);
                    int temp_reg = getReg();

                    /* Word 1: heap pointer */
                    fprintf(target_file, "MOV R%d, [R%d]\n", temp_reg, addr_reg);
                    fprintf(target_file, "PUSH R%d\n", temp_reg);

                    /* Word 2: vtable pointer */
                    fprintf(target_file, "ADD R%d, 1\n", addr_reg);
                    fprintf(target_file, "MOV R%d, [R%d]\n", temp_reg, addr_reg);
                    fprintf(target_file, "PUSH R%d\n", temp_reg);

                    freeReg();
                    freeReg();

                    arg_words += 2;
                } else {
                    /* Normal one-word argument */
                    int reg = codeGen(actual_arg);
                    fprintf(target_file, "PUSH R%d\n", reg);
                    freeReg();

                    arg_words++;
                }

                arg = arg->right;
            }

            fprintf(target_file, "PUSH R0\n");
            fprintf(target_file, "CALL F%d\n", g->flabel);

            int res_reg = getReg();
            fprintf(target_file, "POP R%d\n", res_reg);

            int discard_reg = getReg();
            for (int i = 0; i < arg_words; i++) {
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