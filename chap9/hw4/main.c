#include <stdio.h>
#include <stdlib.h>
#include <string.h>  

#define MAXARG 10

int main(int argc, char *argv[]) { 
    char input[100];           
    char *args[MAXARG];        
    char *saveptr;            
    int status;
	while(1) {
    printf("Input CMD : \n");
    fgets(input, sizeof(input), stdin);

	printf("[%d] Parent process start\n", getpid());
    input[strcspn(input, "\n")] = '\0';  

    int i = 0;
    char *token = strtok_r(input, " ", &saveptr);  

    while (token != NULL && i < MAXARG - 1) {
        args[i++] = token; 
        token = strtok_r(NULL, " ", &saveptr);  
    }

	args[i] = NULL;

    int pid = fork();

    if(pid == 0) { // Child Process
        printf("[%d] Child Process Start \n", getpid());
        if(execvp(args[0], args) < 0) {
			perror("Command Execute Fail");
        	exit(1);
		}
    }

    int child = wait(&status);
	if(WIFEXITED(status)) {
	    printf("[%d] Child Process %d End \n", getpid(), child);
		printf("SUCCESS\n");
	}

	printf("[%d] Parent Process End\n", getpid());
	}
}
