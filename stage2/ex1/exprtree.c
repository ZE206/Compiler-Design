#include "exprtree.h"

/* Memory storage array for variables 'a' through 'z' */
int var[26];

int evaluate(struct tnode *t) {
    if (t == NULL) return 0;

    switch (t->type) {
        case NODE_NUM:
            return t->val;

        case NODE_VAR:
            /* Return variable value from array (a = index 0, z = index 25) */
            return var[t->varname[0] - 'a'];

        case NODE_OP: {
            int leftVal = evaluate(t->left);
            int rightVal = evaluate(t->right);

            switch (t->val) {
                case '+': return leftVal + rightVal;
                case '-': return leftVal - rightVal;
                case '*': return leftVal * rightVal;
                case '/': 
                    if (rightVal == 0) {
                        fprintf(stderr, "Runtime Error: Division by zero!\n");
                        exit(1);
                    }
                    return leftVal / rightVal;
            }
            break;
        }

        case NODE_ASSIGN: {
            int val = evaluate(t->right);
            var[t->left->varname[0] - 'a'] = val;
            return 0;
        }

        case NODE_READ: {
            int val;
            printf("Enter value for %s: ", t->left->varname);
            scanf("%d", &val);
            var[t->left->varname[0] - 'a'] = val;
            return 0;
        }

        case NODE_WRITE: {
            int val = evaluate(t->left);
            printf("OUTPUT: %d\n", val);
            return 0;
        }

        case NODE_CONN:
            evaluate(t->left);
            evaluate(t->right);
            return 0;
    }

    return 0;
}

struct tnode* createTree(int val, int type, char* c, struct tnode *l, struct tnode *r) {
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