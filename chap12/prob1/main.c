#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXLINE 100

int main() {
    int n, length, fd[2], pid;
    char message[MAXLINE], line[MAXLINE];

    pipe(fd); // Create Pipe

    if((pid = fork()) == 0) {
        close(fd[0]); // delete read fd
        sprintf(message, "Hello from PID %d\n", getpid());
        length = strlen(message) + 1;
        write(fd[1], message, length);
    } else {
        close(fd[1]); // delete write fd
        n = read(fd[0], line, MAXLINE);
        printf("[%d] %s", getpid(), line);
    }

    exit(0);
}
