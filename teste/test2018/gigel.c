#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 201

int main()
{
	int n, mat[MAX][MAX];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 5) {
				for (int k = abs(j - i); ;)
			}
		}
	}

    return 0;
}