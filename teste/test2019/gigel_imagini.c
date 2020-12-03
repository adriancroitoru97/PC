//Copyright Adrian Croitoru

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define NMAX 100

int main() {
	short nc, mc;
	short i, j;
	short x;
	short d[2 * NMAX][2 * NMAX];

	scanf("%hd %hd", &nc, &mc);

	for (i = 0; i < nc; i++) {
		for (j = 0; j < mc; j++) {
			scanf("%hd", &x);
			d[2 * i][2 * j] = x % 2;
			d[2 * i][2 * j + 1] = x % 3;
			d[2 * i + 1][2 * j] = x % 12;
			d[2 * i + 1][2 * j + 1] = x % 13;
		}
	}
	printf("%hd %hd\n", 2 * nc, 2 * mc);
	for (i = 0; i < 2 * nc; i++) {
		for (j = 0; j < 2 * mc; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}

    return 0;
}

