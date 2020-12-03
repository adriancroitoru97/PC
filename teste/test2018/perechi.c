#include <stdio.h>
#define MAX 100000

void sortare(int a, int n, int *temp, int *oras)
{
	for (int i = a; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (temp[i] > temp[j]) {
				int aux1 = temp[i], aux2 = oras[i];
				temp[i] = temp[j];
				oras[i] = oras[j];
				temp[j] = aux1;
				oras[j] = aux2;
			} else if (temp[i] == temp[j]) {
				if (oras[i] > oras[j]) {
				int aux1 = temp[i], aux2 = oras[i];
				temp[i] = temp[j];
				oras[i] = oras[j];
				temp[j] = aux1;
				oras[j] = aux2;
			}
			}
		}
	}
}

int main()
{
	int n, oras[MAX], temp[MAX];
	int oras_2[MAX], temp_2[MAX];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &temp[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &oras[i]);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (temp[i] % 2 == 0) {
			temp_2[cnt] = temp[i];
			oras_2[cnt] = oras[i];
			cnt++;
		}
	}
	sortare(0, cnt, temp_2, oras_2);
	int tempo = cnt;

	for (int i = 0; i < n; i++) {
		if (temp[i] % 2 == 1) {
			temp_2[cnt] = temp[i];
			oras_2[cnt] = oras[i];
			cnt++;
		}
	}
	sortare(tempo, cnt, temp_2, oras_2);

	for (int i = 0; i < n; i++)
		printf("%d ", temp_2[i]);
	printf("\n");

	for (int i = 0; i < n; i++)
		printf("%d ", oras_2[i]);
	printf("\n");


	return 0;
}