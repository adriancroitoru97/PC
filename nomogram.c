//Adrian-Valeriu Croitoru, 312CA

#include <stdio.h>
#define MAX 101

//citeste o matrice
void citire_matrice(int n, int m, int matrice[][MAX])
{
	for (int j = 0; j < n; j++)
		for (int k = 0; k < m; k++)
			scanf("%d", &matrice[j][k]);
}

//citeste precizarile despre linii si coloane, sub forma unei matrice
void citire_precizari(int n, int v[][MAX])
{
	int nr_grupuri;

	for (int j = 0; j < n; j++) {
		scanf("%d", &nr_grupuri);
		v[j][0] = nr_grupuri;
		for (int k = 1; k <= nr_grupuri; k++)
			scanf("%d", &v[j][k]);
	}
}

//
int verificare(int n, int m, int matrice[][MAX], int v[][MAX], int i)
{
	//int i = 1 pt verificare linie, 2 pt verificare coloana
	int nr_grupuri, elem_grup_actual, nr_grupuri_gasite;
	int sunt_in_grup;
	int j, k, cnt;
	int j1, k1;

	for (j = 0; j < n; j++) {   // linia / coloana curenta
		nr_grupuri = v[j][0];  // nr de grupuri de pe o linie / coloana j
		sunt_in_grup = 0;
		elem_grup_actual = 0;
		cnt = 1;
		nr_grupuri_gasite = 0;

		for (k = 0; k < m; k++) {  // parcurgere coloana/linie curenta
			//daca verificarea e pe coloane, se interschimba j si k
			if (i == 1) {
				j1 = j;
				k1 = k;
			} else {
				j1 = k;
				k1 = j;
			}

			//cand gasesc 0, verific sa fie ok matricea in raport cu precizarile
			if (matrice[j1][k1] == 0 && sunt_in_grup) {
				if (elem_grup_actual != v[j][cnt])
					return 0;

				//reinitializez variabilele de verificare
				cnt++;
				nr_grupuri_gasite++;
				sunt_in_grup = 0;
				elem_grup_actual = 0;
			} else if (matrice[j1][k1] == 1) {
				//cand gasesc 1, sunt intr-un grup, continui verificarea
				elem_grup_actual++;
				sunt_in_grup = 1;
			}
		}

		//daca ultimul element de pe o linie/coloana e 1, inchid grupul
		if (sunt_in_grup && elem_grup_actual == v[j][cnt])
			nr_grupuri_gasite++;

		//nr de grupuri gasite trebuie sa fie egal cu cel din precizari
		if (nr_grupuri_gasite != nr_grupuri)
			return 0;
		}
		return 1;
}

int main(void)
{
	int T, i;
	int n, m;
	int linii[MAX][MAX], coloane[MAX][MAX], matrice[MAX][MAX];
	int ver;

	scanf("%d", &T);

	for (i = 0; i < T; ++i) { //rulare puzzle curent
		scanf("%d %d", &n, &m);

		citire_precizari(n, linii);
		citire_precizari(m, coloane);
		citire_matrice(n, m, matrice);

		ver = verificare(n, m, matrice, linii, 1); //verificare pe linii

		//verific pe coloane doar daca pe linii verificare e ok
		if (ver)
			ver = verificare(m, n, matrice, coloane, 2); //verificare pe coloane

		if (ver == 0)
			printf("Eroare\n");
		else
			printf("Corect\n");
	}

	return 0;
}
