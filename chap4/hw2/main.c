#include <stdio.h>

int main(int argc, char* argv[]) {
	FILE* fp;
	int c;
	if(argc < 2) fp = stdin;

	for(int i = 1; i < argc; i++) {
		fp = fopen(argv[i], "r");
		c = getc(fp);
		int line = 0;

		fputs(line, stdout);
		while(c != EOF) {
			fputc(c, stdout);
			c = getc(fp);

			if(c == '\n') {
				fputc(c, stdout);
				fputs(line, stdout);
				line++;
			}
		}
	}

	fclose(fp);

	return 0;
}
