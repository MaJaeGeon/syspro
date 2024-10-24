#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#define START_ID 1

int main(int argc, char* argv[]) {
	FILE *fp;

	if ((fp = fopen("db.dat", "ab+")) == NULL ) {
		fprintf(stderr, "Error Open File\n");
		return 2;
	}

	printf("--Goods update--\n");
	printf("(n): sell one goods ] ");
	
	int id;
	struct item rec;

	scanf("%d", &id);

	fseek(fp, (id - START_ID) * sizeof(rec), SEEK_SET);

	if((fread(&rec, sizeof(rec), 1, fp) > 0)) {
		fseek(fp, -sizeof(rec), SEEK_CUR);
		rec.stock--;
		fwrite(&rec, sizeof(rec),1, fp);
	}
	else {
		printf("can't read block num : %d", id);
		exit(1);
	}
	
	rewind(fp);
	printf("%-2s %-4s %-8s %-12s %-5s\n", "id", "name", "category", "expired date", "stock");
	while(fread(&rec, sizeof(rec), 1, fp) > 0) {
		printf("%4d %20s %20s %4d %4d\n", rec.id, rec.name, rec.category, rec.expiredDate, rec.stock);
	}

	fclose(fp);
	exit(0);
}

