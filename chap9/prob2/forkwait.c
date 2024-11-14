#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int pid, child, status;

    printf("[%d] Parental Process Start \n", getpid());

    pid = fork();
    if (pid == 0) {
        printf("[%d] Child Process Start \n", getpid());
        exit(1);
    }

    child = wait(&status);
    printf("[%d] Child Process %d End \n", getpid(), child);
    
    printf("\tEnd Code %d\n", status>>8);
}
