//Adrian-Valeriu Croitoru, 312CA

#include <stdio.h>

//afisez un vector intre 2 pozitii date
void afisare_vector(int inceput, int sfarsit, int v[])
{
	for (int i = inceput; i <= sfarsit; i++)
		printf("%d ", v[i]);
}

//cauta secventa care se repeta
//daca o gaseste, afiseaza nr de diferente, dar si secventa efectiva
int cautare_vector(int n, int v[])
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i] == v[j]) {
				printf("%d\n", i);
				afisare_vector(i, j - 1, v);
				return 1;
			}
		}
	}

	return 0;
}

//transpune un numar intr-un vector de frecventa
void numar_in_vector(int n, int cifre[])
{
	int p = n;

	while (p) {
		cifre[p % 10]++;
		p /= 10;
	}
}

//ordonez crescator numarul n
int ordonare_crescatoare(int n)
{
	int cifre[10] = {0};
	int numar_final = 0;

	numar_in_vector(n, cifre);

	for (int i = 1; i < 10; i++)
		for (int j = 0; j < cifre[i]; j++)
			numar_final = numar_final * 10 + i;

	return numar_final;
}

//ordonez descrescator numarul n
int ordonare_descrescatoare(int n)
{
	int cifre[10] = {0};
	int numar_final = 0;

	numar_in_vector(n, cifre);

	for (int i = 9; i >= 0; i--)
		for (int j = 0; j < cifre[i]; j++)
			numar_final = numar_final * 10 + i;

	return numar_final;
}

int main(void)
{
	int N;
	int v[120];
	int dif;
	int nr_diferente = 0;

	scanf("%d", &N);

	//se repeta pana cand gaseste secventa care se repeta, apoi efectueaza break
	for (;;) {
		dif = ordonare_descrescatoare(N) - ordonare_crescatoare(N);
		v[nr_diferente] = dif;
		N = dif;
		nr_diferente++;
		if (cautare_vector(nr_diferente, v))
			break;
	}

	return 0;
}
