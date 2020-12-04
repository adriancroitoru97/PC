#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int n, x;
	int frecv[50] = {0};
	int numere[50];

	for (int i = 1; i <= 49; i++)
		numere[i] = i;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			scanf("%d", &x);
			frecv[x]++;
		}
	}

	for (int i = 1; i < 49; i++) {
		for (int j = i + 1; j <= 49; j++) {
			if (frecv[i] < frecv[j]) {
				int aux_frecv = frecv[i];
				int aux_nr = numere[i];
				frecv[i] = frecv[j];
				numere[i] = numere[j];
				frecv[j] = aux_frecv;
				numere[j] = aux_nr;
			} else if (frecv[i] == frecv[j] && numere[i] > numere[j]) {
				int aux_frecv = frecv[i];
				int aux_nr = numere[i];
				frecv[i] = frecv[j];
				numere[i] = numere[j];
				frecv[j] = aux_frecv;
				numere[j] = aux_nr;
			}
		}
	}

	for (int i = 1; i <= 6; i++)
		printf("%d ", numere[i]);
	printf("\n");

	return 0;
}
