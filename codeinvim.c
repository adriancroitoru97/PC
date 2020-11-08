//Adrian-Valeriu Croitoru, 312CA

#include <stdio.h>
#define MAX 101

//functie care citeste un vector
void citire_vector(int n, int v[])
{
	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);
}

//calculeaza totalul punctelor pe care le are studentul
// potentialul de marire al punctelor = (10 - nota) * creditele
int puncte_student(int n, int note[], int credite[], int potential[])
{
	int S = 0;

	for (int i = 0; i < n; ++i) {
		S += note[i] * credite[i];
		potential[i] = (10 - note[i]) * credite[i];
	}

	return S;
}

//sortare descrescatoare a unui vector
void sortare_vector(int n, int v[])
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i] < v[j]) {
				int aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
}

//calculeaza potentialul total al studentului de marire a punctelor
int potential_total(int n, int v[])
{
	int S = 0;

	for (int i = 0; i < n; ++i)
		S += v[i];

	return S;
}

int main(void)
{
	int n, note[MAX], credite[MAX], p_min;
	int potential[MAX];
	int puncte, s_potential;
	int m = 0;

	scanf("%d", &n);
	citire_vector(n, note);
	citire_vector(n, credite);
	scanf("%d", &p_min);

	//calculeaza punctele pe care le are studentul
	//calculeaza punctele potentiale pe care le mai poate obtine
	puncte = puncte_student(n, note, credite, potential);
	s_potential = potential_total(n, potential);

	if (s_potential + puncte < p_min) {
		//cazul imposibil
		m = -1;
	} else {
		//sortez punctele potentiale
		//incep de la materia cu cele mai multe puncte potentiale
		sortare_vector(n, potential);

		//adun puncte potentiale la totalul punctelor studentului
		//daca s-a depasit pragul minim, ma opresc
		for (int i = 0; i < n; i++) {
			if (puncte + potential[i] >= p_min) {
				m++;
				break;
			}
				puncte += potential[i];
				m++;
		}
	}

	printf("%d\n", m);

	return 0;
}
