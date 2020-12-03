#include <stdio.h>
#define MAX 2005

int main()
{
	int n_secventa, n_sablon;
	int secventa[MAX], sablon[MAX];
	int nr = 0;

	scanf("%d", &n_secventa);
	for (int i = 0; i < n_secventa; i++)
		scanf("%d", &secventa[i]);

	scanf("%d", &n_sablon);
	for (int i = 0; i < n_sablon; i++)
		scanf("%d", &sablon[i]);

	for (int i = 0; i <= n_secventa - n_sablon; i++) {
		int ver = 1;
		for (int j = i; j < i + n_sablon; j++) {
			if (secventa[j] != sablon[j - i]) {
				ver = 0;
				break;
			}
		}
		if (ver)
			nr++;
	}

	printf("%d\n", nr);

	return 0;
}