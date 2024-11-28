#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void intHandler();

int main() {
    signal(SIGINT, intHandler);

    while(1) {
        pause();
    }

    printf("end\n");
}

void intHandler(int sigNo) {
    printf("Inturrupt Signal\n");
    printf("Signal Number : %d\n", sigNo);
    exit(0);
}
