#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprtree.h"
#include "y.tab.h"

/* Memory space for 26 variables ('a' to 'z') */
int memory[26];

struct tnode* createTree(int val, int type, char* varname, int nodetype, 
                         struct tnode *l, struct tnode *m, struct tnode *r) {
    
    /* Type checking */
    if (nodetype == NODE_OP) {
        if (l->type != TYPE_INT || r->type != TYPE_INT) {
            fprintf(stderr, "Type Mismatch Error: Arithmetic operations require integer operands\n");
            exit(1);
        }
    }
    if (nodetype == NODE_RELOP) {
        if (l->type != TYPE_INT || r->type != TYPE_INT) {
            fprintf(stderr, "Type Mismatch Error: Relational operators require integer operands\n");
            exit(1);
        }
    }

    struct tnode *temp = (struct tnode*)malloc(sizeof(struct tnode));
    if (!temp) {
        fprintf(stderr, "Memory allocation error\n");
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
    temp->mid = m;
    temp->right = r;

    return temp;
}

/* Recursive AST Interpreter */
int evaluate(struct tnode *t) {
    if (t == NULL) return 0;

    switch (t->nodetype) {
        case NODE_NUM:
            return t->val;

        case NODE_VAR:
            return memory[t->varname[0] - 'a'];

        case NODE_OP: {
            int leftVal = evaluate(t->left);
            int rightVal = evaluate(t->right);
            switch (t->val) {
                case '+': return leftVal + rightVal;
                case '-': return leftVal - rightVal;
                case '*': return leftVal * rightVal;
                case '/': 
                    if (rightVal == 0) {
                        fprintf(stderr, "Runtime Error: Division by zero\n");
                        exit(1);
                    }
                    return leftVal / rightVal;
            }
            break;
        }

        case NODE_RELOP: {
            int leftVal = evaluate(t->left);
            int rightVal = evaluate(t->right);
            switch (t->val) {
                case LT: return leftVal < rightVal;
                case GT: return leftVal > rightVal;
                case LE: return leftVal <= rightVal;
                case GE: return leftVal >= rightVal;
                case EQ: return leftVal == rightVal;
                case NE: return leftVal != rightVal;
            }
            break;
        }

        case NODE_ASSIGN: {
            int val = evaluate(t->right);
            memory[t->left->varname[0] - 'a'] = val;
            return 0;
        }

        case NODE_READ: {
            int val;
            printf("Enter input for variable %s: ", t->left->varname);
            scanf("%d", &val);
            memory[t->left->varname[0] - 'a'] = val;
            return 0;
        }

        case NODE_WRITE: {
            int val = evaluate(t->left);
            printf("%d\n", val);
            return 0;
        }

        case NODE_CONN:
            evaluate(t->left);
            evaluate(t->right);
            return 0;

        case NODE_IF:
            if (evaluate(t->left)) {
                evaluate(t->mid);
            }
            return 0;

        case NODE_IF_ELSE:
            if (evaluate(t->left)) {
                evaluate(t->mid);      /* Then part */
            } else {
                evaluate(t->right);    /* Else part */
            }
            return 0;

        case NODE_WHILE:
            while (evaluate(t->left)) {
                evaluate(t->right);
            }
            return 0;
    }
    return 0;
}
