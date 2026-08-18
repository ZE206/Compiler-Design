#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LABELS 100

typedef struct {
    char name[32];
    int address;
} LabelEntry;

// Label Table
LabelEntry labelTable[MAX_LABELS];
int labelCount = 0;

// Add label entry to table
void addLabel(char* name, int address) {
    strcpy(labelTable[labelCount].name, name);
    labelTable[labelCount].address = address;
    labelCount++;
}

// Get address for a label
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

        // Skip the first 8 header lines
        if (line_num <= 8) continue;

        // Get rid of trailing newline characters
        line[strcspn(line, "\r\n")] = 0;
        if (strlen(line) == 0) continue;

        int len = strlen(line);
        if (line[0] == 'L' && line[len - 1] == ':') {
            line[len - 1] = '\0'; // Strip the colon
            addLabel(line, current_address);
        } else {
            current_address += 2; // Each XSM instruction is 2 words
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

        // Keep the first 8 header lines unchanged
        if (line_num <= 8) {
            fputs(line, fout);
            continue;
        }

        line[strcspn(line, "\r\n")] = 0;
        if (strlen(line) == 0) continue;

        // Strip label definition tags from output
        int len = strlen(line);
        if (line[0] == 'L' && line[len - 1] == ':') {
            continue;
        }

        char op[32], arg1[32], arg2[32];
        int num_args = sscanf(line, "%s %s %s", op, arg1, arg2);

        // Handle single operand jumps: e.g., "JMP L0"
        if (num_args == 2 && arg1[0] == 'L') {
            int addr = getAddress(arg1);
            if (addr != -1) {
                fprintf(fout, "%s %d\n", op, addr);
            } else {
                fprintf(fout, "%s\n", line);
            }
        } 
        // Handle conditional jumps: e.g., "JZ R0, L1"
        else if (num_args == 3 && arg2[0] == 'L') {
            arg1[strcspn(arg1, ",")] = 0; // Strip trailing comma from register
            int addr = getAddress(arg2);
            if (addr != -1) {
                fprintf(fout, "%s %s, %d\n", op, arg1, addr);
            } else {
                fprintf(fout, "%s\n", line);
            }
        } 
        // Normal instructions (MOV, ADD, PUSH, POP, etc.)
        else {
            fprintf(fout, "%s\n", line);
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}