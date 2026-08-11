typedef struct tnode{
    int val;
    char* op;
    struct tnode *left;
    struct tnode *right;
} tnode;
void infix(struct tnode *t);
void postfix(struct tnode *t);
struct tnode* makeLeafNode(int val);
struct tnode* makeOperatorNode(char op,struct tnode *l,struct tnode *r); 
int evaluate(struct tnode *t);