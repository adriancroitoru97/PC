//Adrian-Valeriu Croitoru, 312CA

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void citire_vector(int n, int v[])
{
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
}

int main() {
	int n, v[101], v2[2021] = {0};
	int i, x;
	int max = -2020;

	scanf("%d", &n);
	citire_vector(n, v);

	for (i = 0; i < n; i++) {
		x = v[i];
		if (x > max) {
			max = x;
		}
		v2[x]++;
	}

	for (i = 0; i <n; i++) {
		if(v2[v[i]] > 0) {
			printf("%d ", v[i]);
			v2[v[i]] = 0;
		}
	}

	printf("\n");

    return 0;
}
