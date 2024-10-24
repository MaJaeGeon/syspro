#include <stdio.h>
#include <stdlib.h>
#include "item.h"

int main(int argc, char* argv[]) {
	struct item rec;
	FILE *fp;
	fp = fopen("db.dat", "ab");

	printf("%-2s %-4s %-8s %-12s %-5s\n", "id", "name", "category", "expired date", "stock");
	while(scanf("%d %s %s %d %d", &rec.id, rec.name, rec.category, &rec.expiredDate, &rec.stock) == 5) {
		fwrite(&rec, sizeof(rec), 1, fp);
	}

	fclose(fp);
	exit(0);
}
