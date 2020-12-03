//Adrian-Valeriu Croitoru, 312CA

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define NMAX 100

// functia printeaza transpusa matricei a la stdout
// a are n linii; linia i are m[i] elemente
// functia printeaza mai intai dimensiunile, apoi matricea, conform indicatiilor din enunt

void mat_zero(int b[][NMAX])
{
    for (int i = 0; i < NMAX; i++) {
        for (int j = 0; j < NMAX; j++) {
                b[i][j] = 0;
        }
    }
}
void transpose_matrix_varlen(int n, int m[NMAX], int a[NMAX][NMAX])
{
    int v[NMAX];
    int b[NMAX][NMAX];
    int nr, nrt = 0;

    mat_zero(b);

    for (int i = 0; i < NMAX; i++) {
        nr = 0;
        for (int j = 0; j < NMAX; j++) {
            if(a[j][i]) {
                b[i][j] = a[j][i];
                nr++;
            }
        }
        if (nr) {
            v[i] = nr;
            nrt++;
        }
    }

    printf("%d\n", nrt);
    for(int i = 0; i < nrt; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    for (int i = 0; i < nrt; i++) {
        for (int j = 0; j < NMAX; j++) {
            if(b[i][j]) {
                printf("%d ", b[i][j]);
            }
        }
        printf("\n");
    }

}

int main() {
    int n;
    scanf("%d", &n);
    
    int m[NMAX];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &m[i]);
    }
    
    int a[NMAX][NMAX];

    mat_zero(a);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m[i]; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    
    transpose_matrix_varlen(n, m, a);

    return 0;
}