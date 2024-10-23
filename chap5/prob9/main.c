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

    while(lineNum-- > 0) {
      printf("%s\n", lines[lineNum]);
    }
    return 0;
}

