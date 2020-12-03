#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define NMAX 1000
// NU ai voie sa modifici mai sus

// n este lungimea celor 2 vectori de caractere (atentie!!! sunt vectori!!!)
// compara vectorul v cu vectorul w
//    - returneaza 1 daca v este anagrama a lui w
//    - returneaza 0 daca v NU este angrama a lui v
int is_anagram(int n, char *v, char *w) {
    int cnt_v[30] = {0}, cnt_w[30] = {0};

    for (int i = 0; i < n; i++) {
        int temp1, temp2;
        temp1 = v[i] - 97;
        temp2 = w[i] - 97;
        cnt_v[temp1]++;
        cnt_w[temp2]++; 
    }

    for (int i = 0; i < 26; i++) {
        if (cnt_w[i] != cnt_v[i])
            return 0;
    }
    return 1;
    return -1;
}

// NU ai voie sa modific mai jos
void solve() {
    char v[NMAX + 1], w[NMAX + 1];
    scanf("%s%s", v, w);
    
    int n = strlen(v);
    v[n] = ':';
    w[n] = '*';
    
    char *msg;
    switch(is_anagram(n, v, w)) {
        case 1: {
            msg = "DA";
            break;
        }
        case 0: {
            msg = "NU";
            break;
        }
        default: {
            msg = "mumu (nu ai implementat functia. ce vrei sa pice ponei din cer?)";
            break;
        }
    }
    printf("%s\n", msg);
}

int main() {
    int tests;
    scanf("%d", &tests);
    
    while (tests--) {
        solve();
    }
    
    return 0;
}