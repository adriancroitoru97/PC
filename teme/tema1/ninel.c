//Adrian-Valeriu Croitoru, 312CA

#include <stdio.h>
#define MAX 10000000

int copac_special(int a, int b, int c)  //verifica daca un copac este special
{
	if (a && b && c) {
		if (a < b && b > c)
			return 1;
	}

	return 0;
}

int main(void)
{
	int i, nr_copaci_speciali = 0;
	int N;
	int x = 0, x_urmator, x_anterior;
	long S = 0;
	int xmax_impar = 0, xmin_par = MAX;
	int nr_copaci_speciali_impari = 0, nr_copaci_speciali_pari = 0;
	double m_a;

	scanf("%d", &N); //scanez numarul de copaci
	scanf("%d", &x_urmator); //scanez primul copac

	//scanez restul, memorez cate 3 copaci consecutivi
	for (i = 1; i < N; i++) {
		x_anterior = x;
		x = x_urmator;
		scanf("%d", &x_urmator);

		//verific daca un copac e special
		if (copac_special(x_anterior, x, x_urmator)) {
			S += x;
			nr_copaci_speciali++;

			if ((i - 1) % 2 == 1) {
				nr_copaci_speciali_impari++;
				if (x > xmax_impar)
					xmax_impar = x;
			} else {
				nr_copaci_speciali_pari++;
				if (x < xmin_par)
					xmin_par = x;
			}
		}
	}

	//caz particular media aritmetica
	if (nr_copaci_speciali == 0)
		m_a = 0;
	else
		m_a = (double)S / nr_copaci_speciali;

	//cazuri particulare copac min si max
	if (!nr_copaci_speciali_pari && !nr_copaci_speciali_impari) {
		xmax_impar = 0;
		xmin_par = 0;
	} else if (!nr_copaci_speciali_impari && nr_copaci_speciali_pari) {
		xmax_impar = -1;
	} else if (nr_copaci_speciali_impari && !nr_copaci_speciali_pari) {
		xmin_par = -1;
	}

	printf("%ld\n", S);
	printf("%.7lf\n", m_a);
	printf("%d\n", xmax_impar);
	printf("%d\n", xmin_par);

	return 0;
}
