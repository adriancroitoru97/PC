#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100

int main() {
    int n, m, mat[MAX][MAX];

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    	for (int j = 0; j < m; j++)
    		scanf("%d", &mat[i][j]);

    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (i == j)
    			printf("%d ", mat[i][j]);
    	}
    }
    printf("\n");

    for (int i = n - 1; i >= 0; i--) {
    	for (int j = 0; j < m; j++) {
    		if (i + j == m - 1)
    			printf("%d ", mat[i][j]);
    	}
    }
    printf("\n");

    return 0;
}