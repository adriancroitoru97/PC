#include <stdio.h>
#define MAX 10000

void sort(int n, double *v)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++) 
			if (v[i] > v[j]) {
				double aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
}
int main()
{
	int n;
	double v[MAX];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf", &v[i]);

	sort(n, v);

	printf("%lf\n", v[0]);
	printf("%lf\n", v[n - 1]);
	
	if (n % 2)
		printf("%lf\n", v[n / 2]);
	else
		printf("%lf\n", (v[n / 2 - 1] + v[n / 2]) / 2);

	return 0;
}