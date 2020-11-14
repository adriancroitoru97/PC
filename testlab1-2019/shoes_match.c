//Copyright Adrian Croitoru

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define NMAX 1000

void sort_array(int v[], int n) {
	int i, j, aux;

	for (i = 0; i < n - 1; i++) {
		for(j = i + 1; j < n; j++) {
			if (v[i] > v[j]) {
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
}

int do_they_match(int *left, int n_left, int *right, int n_right) {
	int i;

	if (n_right != n_left) {
		return 0;
	}

	sort_array(left, n_left);
	sort_array(right, n_right);

	for (i = 0; i < n_left; i++) {
		if (left[i] != right[i]) {
			return 0;
		}
	}

	return 1;
}

void read_vector(int v[], int *n) {
	scanf("%d", n);
	for(int i = 0; i < *n; i++) {
		scanf("%d", &v[i]);
	}
}

int main() {
	int n_tests, left[NMAX], right[NMAX], n_left, n_right;
    scanf("%d", &n_tests);
	for(int i = 0; i < n_tests; i++) {
		read_vector(left, &n_left);
		read_vector(right, &n_right);
		if(do_they_match(left, n_left, right, n_right)) {
			puts("True");
		} else {
			puts("False");
		}
	}

	return 0;

}

