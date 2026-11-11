#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LABELS 1000

typedef struct {
    char name[32];
    int address;
} LabelEntry;

LabelEntry labelTable[MAX_LABELS];
int labelCount = 0;

void addLabel(char* name, int address) {
    strcpy(labelTable[labelCount].name, name);
    labelTable[labelCount].address = address;
    labelCount++;
}

int getAddress(char* name) {
    for (int i = 0; i < labelCount; i++) {
        if (strcmp(labelTable[i].name, name) == 0) {
            return labelTable[i].address;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <intermediate.xsm> <final_target.xsm>\n", argv[0]);
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if (!fin) {
        perror("Error opening intermediate file\n");
        return 1;
    }

    char line[256];
    int line_num = 0;
    int current_address = 2056;

    /* PASS 1: Build Label Table */
    while (fgets(line, sizeof(line), fin)) {
        line_num++;
        if (line_num <= 8) continue;

        line[strcspn(line, "\r\n")] = 0;
        if (strlen(line) == 0) continue;

        int len = strlen(line);
        if (len > 0 && line[len - 1] == ':') {
            line[len - 1] = '\0';
            addLabel(line, current_address);
        } else {
            current_address += 2;
        }
    }

    rewind(fin);

    /* PASS 2: Substitute Labels with Concrete Addresses */
    FILE *fout = fopen(argv[2], "w");
    if (!fout) {
        perror("Error creating final target file\n");
        fclose(fin);
        return 1;
    }

    line_num = 0;

    while (fgets(line, sizeof(line), fin)) {
        line_num++;
        if (line_num <= 8) {
            fputs(line, fout);
            continue;
        }

        line[strcspn(line, "\r\n")] = 0;
        if (strlen(line) == 0) continue;

        int len = strlen(line);
        if (len > 0 && line[len - 1] == ':') {
            continue;
        }

        char op[32], arg1[32], arg2[32];
        int num_args = sscanf(line, "%s %s %s", op, arg1, arg2);

        if (num_args == 2 && (strcmp(op, "JMP") == 0 || strcmp(op, "CALL") == 0)) {
            int addr = getAddress(arg1);
            if (addr != -1) {
                fprintf(fout, "%s %d\n", op, addr);
            } else {
                fprintf(fout, "%s\n", line);
            }
        } 
        else if (num_args == 3 && (strcmp(op, "JZ") == 0 || strcmp(op, "JNZ") == 0)) {
            arg1[strcspn(arg1, ",")] = 0;
            int addr = getAddress(arg2);
            if (addr != -1) {
                fprintf(fout, "%s %s, %d\n", op, arg1, addr);
            } else {
                fprintf(fout, "%s\n", line);
            }
        }
        /* STAGE 7 FIX: Resolve function labels in VTable initialization (e.g., MOV R0, F0) */
        else if (num_args == 3 && strcmp(op, "MOV") == 0) {
            arg1[strcspn(arg1, ",")] = 0;
            int addr = getAddress(arg2);
            if (addr != -1) {
                fprintf(fout, "MOV %s, %d\n", arg1, addr);
            } else {
                fprintf(fout, "%s\n", line);
            }
        }
        else {
            fprintf(fout, "%s\n", line);
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}