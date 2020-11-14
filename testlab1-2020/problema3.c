//Adrian-Valeriu Croitoru, 312CA

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n, m[1001][1001];
	int i, j;
	int s = 0;
	int max = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &m[i][j]);
			if (i == j) {
				int x = m[i][j];
				if (x < 0) {
					x = -x;
				}
				s = s + x % 10;
			} 
		}
	}

	max = m[0][n-1];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i + j == n - 1) {
				if (m[i][j] > max) {
					max = m[i][j];
				}
			}
		}
	}


	for (i = 0; i < n; i++) {
		printf("%d ", m[0][i]);
	}
	printf("\n");


	for (i = 0; i < n; i++) {
		printf("%d ", m[i][n-1]);
	}
	printf("\n%d\n", s);
	printf("%d\n", max);

    return 0;
}
