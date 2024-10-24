#include <stdio.h>
#include <string.h>

#define MAX 100

int main(int argc, char *argv[]) {
	if(argc < 2) return 1;

	FILE* fp;
	int mode = 0;

	if(argc == 2) {
		fp = fopen(argv[1], "r");
		mode = 0;
	}
	else if(argc == 3) {
		fp = fopen(argv[2], "r");
		mode = 1;
	} 
	else return 1;
	
	int lineNum = 0;
	char lines[MAX][MAX];
	
	while(fgets(lines[lineNum], MAX, fp) != NULL) {
		lines[lineNum][strcspn(lines[lineNum], "\n")] = '\0';
		lineNum++;
	}

	if(mode) {
		
	}
	else {
		for(int i = 0; i < 2; i++) {
			printf("%s\n", lines[i]);
		}
	}
}
