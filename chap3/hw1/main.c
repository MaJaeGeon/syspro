#include <stdio.h>
#include <string.h>
#include "copy.h"

int main() {
    char arr[5][MAXLINE];
    char temp[MAXLINE];

    int i = 0, j = 0;

    while(i < 5) {
        scanf("%s", arr[i]);
        i++;
    }

    for(i = 0; i < 4; i++) {
        for(j = i + 1; j < 5; j++) {
            if(strlen(arr[i]) < strlen(arr[j])) {
                copy(arr[i], temp);
                copy(arr[j], arr[i]);
                copy(temp, arr[j]);
            }
        }
    }

    for(i = 0; i < 5; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}
