#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Parental Process Start\n");

    if (fork( ) == 0) {
        execl("/bin/echo", "echo", "hello", NULL);
        fprintf(stderr,"First Fail"); 
        exit(1);
    }

    printf("Parental Process End\n");
}
