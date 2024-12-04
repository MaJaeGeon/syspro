#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void mySignal(int sigNo, void(*func)(int)) {
  struct sigaction newact;
  struct sigaction oldact;

  newact.sa_handler = func;
  sigfillset(&newact.sa_mask);

  sigaction(sigNo, &newact, &oldact);
}

void alarmHandler(int sigNo) {
  printf("Wake up\n");
  exit(0);
}

int main() {
  mySignal(SIGALRM, alarmHandler);
  alarm(5);
  short i = 1;
  while(1) {
    sleep(1);
    printf("%d second\n", i++);
  }

  printf("End \n");
}
