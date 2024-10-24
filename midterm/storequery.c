#include <stdio.h>
#include <stdlib.h>
#include "item.h"

int main(int argc, char* argv[]) {
	FILE *fp;

	if ((fp = fopen("db.dat", "rb")) == NULL ) {
		fprintf(stderr, "Error Open File\n");
		return 2;
	}

	printf("--Goods query--\n");
	printf("0: list of all goods, 1: list of available goods ) ");
	int input = 0;
	scanf("%d", &input);
	
	struct item rec;

	printf("%-4s %-20s %-20s %-4s %-4s\n", "id", "name", "category", "expired date", "stock");

	while(fread(&rec, sizeof(rec), 1, fp) > 0) {
		if(rec.id != 0) {
			if(input) {
				if(rec.stock > 0 && rec.expiredDate >= 2023)
					printf("%4d %20s %20s %4d %4d\n", rec.id, rec.name, rec.category, rec.expiredDate, rec.stock);
			}
			else
				printf("%4d %20s %20s %4d %4d\n", rec.id, rec.name, rec.category, rec.expiredDate, rec.stock);

		}
	}
}

