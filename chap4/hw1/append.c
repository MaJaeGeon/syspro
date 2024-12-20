#include <stdio.h>

int main(int argc, char* argv[]) {
	char c;
	FILE *fp1, *fp2;

	if(argc != 3) {
		fprintf(stderr, "How to use : %s file1 file2\n", argv[0]);
		return 1;
	}

	fp1 = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "a+");

	if(fp1 == NULL || fp2 == NULL) {
		fprintf(stderr, "File Open Error\n");
		return 2;
	}

	while((c = fgetc(fp1)) != EOF) fputc(c, fp2);

	fclose(fp1);
	fclose(fp2);

	return 0;
}
