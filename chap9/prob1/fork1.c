#include <stdio.h>
#include <unistd.h>

int main() {
    int pid;
    printf("[%d] Process Start\n", getpid());
    pid = fork();
    printf("[%d] Process : retrun value %d\n", getpid(), pid);
}
