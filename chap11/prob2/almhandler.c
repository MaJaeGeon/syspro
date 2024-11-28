#include <stdio.h>
#include <signal.h>

void alarmHandler();

int main() {
    signal(SIGALRM, alarmHandler);
    alarm(5);

    short i = 0;
    while(1) {
        sleep(1);
        printf("%d second\n", ++i);
    }

    printf("end\n");
}

void alarmHandler(int sigNo) {
    printf("Wake Up\n");
    exit(0);
}
