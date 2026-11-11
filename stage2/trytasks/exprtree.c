#include "exprtree.h"

int regCount=-1;
int getReg(){
    if (regCount>=19){
        fprintf(stderr, "Out of registers\n");
        exit(1);
    }
    regCount++;
    return regCount;
}

void freeReg(){
    if(regCount>0){
        regCount--;
        return;
    }
}

int getMemoryAddress(char var){
    return 4096+(var-'a');
}

extern FILE* targetFile;

int codeGen(struct tnode* t){
    if(t==NULL){
        return -1;
    } 
    int reg;
    switch(t->type){
        case NODE_NUM:{
            reg=getReg();
            fprintf(targetFile,"MOV R%d, %d",reg,  t->val);
            return reg;
        }
        case NODE_VAR:{
            if(t->varname==NULL){
                fprintf(stderr,"Error: Node has NULL var name\n");
                exit(1);
            }
            reg=getReg();
            int addr=getMemoryAddress(t->varname[0]);
            fprintf(targetFile, "MOV R%d, [%d]",reg, addr);
            freeReg();
            return reg;
        }

        case NODE_OP:{
            int leftReg=codeGen(t->left);
            int rightReg=codeGen(t->right);

            switch(t->val){
                case '+':{
                    fprintf("ADD R%d, R%d",leftReg, rightReg);
                    freeReg();
                    return leftReg;
                }
                case '-':{
                    fprintf("SUB R%d,R%d", leftReg, rightReg);
                    freeReg();
                    return leftReg;
                }
                case '/':{
                    fprintf("DIV R%d, R%d", leftReg, rightReg);
                    freeReg();
                    return leftReg;
                }
                case '*':{
                    fprintf("MUL R%d, R%d", leftReg, rightReg);
                    freeReg();
                    return leftReg;
                }
                
            }
        }

        case NODE_ASSIGN:{
            if(t->left==NULL || t->right==NULL){
                fprintf(stderr, "Error: Invalid target variable in assign\n");
                exit(1);
            }
            int rightReg=codeGen(t->right);
            int addr=getMemoryAddress(t->left->varname);
            fprintf(targetFile, "MOV [%d],R%d",addr, rightReg);
            freeReg();
            return -1;
        }

        case NODE_READ:{
            if(t->left==NULL || t->right==NULL){
                fprintf(stderr, "Error: Invalid  variable in READ\n");
                exit(1);
            }

            int addr=getMemoryAddress(t->left->varname[0]);
            reg=getReg();
            fprintf(targetFile ,"MOV R%d, \"Read\"\n");
            fprintf(targetFile, "PUSH R%d, ]p11111111111111111pppppppppppppppppppppppppp-------------------------------------------------",)
        }
    }
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