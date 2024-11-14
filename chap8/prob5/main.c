#include <stdio.h>
#include <unistd.h>

int main() {
    printf("My Process Num : [%d]\n", getpid());
    printf("My Parent Process Num : [%d]\n", getppid());
}
