#include <stdio.h>
#define MAX 205

int main()
{
	int nd, md;
	int mat[MAX][MAX];
	int mat2[MAX][MAX];

	scanf("%d %d", &nd, &md);
	for (int i = 0; i < nd; i++) {
		for (int j = 0; j < md; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	for (int i = 0; i < nd; i = i + 2) {
		for (int j = 0; j < md; j = j + 2) {
			mat2[i / 2][j / 2] += (mat[i][j] + mat[i + 1][j] + mat[i + 1][j + 1] + mat[i][j + 1]);
			mat2[i / 2][j / 2] %= 2;
		}
	}

	printf("%d %d\n", nd / 2, md / 2);
	for (int i = 0; i < nd / 2; i++) {
		for (int j = 0; j < md / 2; j++) {
			printf("%d ", mat2[i][j]);
		}
		printf("\n");
	}

	return 0;
}