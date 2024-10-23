#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100  
#define MAX_LEN 1024 

int main(int argc, char *argv[]) {
    FILE *fp;
    char lines[MAX_LINES][MAX_LEN];
    int lineNum = 0;

    if(argc != 2) {
        fprintf(stderr, "How to use: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        fprintf(stderr, "File open error: %s\n", argv[1]);
        return 2;
    }

    while(fgets(lines[lineNum], MAX_LEN, fp) != NULL && lineNum < MAX_LINES) {
        lines[lineNum][strcspn(lines[lineNum], "\n")] = '\0';
        lineNum++;
    }

    fclose(fp);

    printf("Total Line : %d\n", lineNum);

    char input[100];
    printf("You can choose 1 ~ %d Line\nPls 'Enter' the line to select : ", lineNum);
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "*") == 0) {
        for (int i = 0; i < lineNum; i++) {
            printf("%s\n", lines[i]);
        }
    }
    else if (strchr(input, '-') != NULL) {
        int start, end;
        sscanf(input, "%d-%d", &start, &end);

        if (start < 1 || end > lineNum || start > end) {
            printf("Invalid range: %d-%d\n", start, end);
        } else {
            for (int i = start; i <= end; i++) {
                printf("%s\n", lines[i - 1]);
            }
        }
    }
    else if (strchr(input, ',') != NULL) {
        char *token = strtok(input, ",");
        while (token != NULL) {
            int line = atoi(token);
            if (line < 1 || line > lineNum) {
                printf("Invalid line number: %d\n", line);
            } else {
                printf("%s\n", lines[line - 1]);
            }
            token = strtok(NULL, ",");
        }
    }
    else if (isdigit(input[0])) {
        int line = atoi(input);
        if (line < 1 || line > lineNum) {
            printf("Invalid line number: %d\n", line);
        } else {
            printf("%s\n", lines[line - 1]);
        }
    }
    else {
        printf("Invalid input format.\n");
    }

    return 0;
}

