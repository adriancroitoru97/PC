#include <stdio.h>
#define NMAX 100
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// xxxxxxxxxxxxxxxxxxx NU edita mai sus de aceasta linie xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


// @n - numarul de elemente din vector
// @v - pointer catre primul element din vector
int prim(int x) {
  if (x < 2)
    return 0;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0)
      return 0;
  }
  
  return 1;
}
int count_primes(int n, int *v) {
    int nr = 0;
    for(int i = 0; i < n; i++) {
      if(prim(v[i]))
        nr++;
    }

    return nr;
}

// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// xxxxxxxxxxxxxxxxxxx NU edita functia main xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int main() {
    // Datele sunt citite de la STDIN si sunt afisate la STDOUT.    
    int n, v[NMAX];
  
  	// citesc numarul de elemente
  	scanf("%d", &n);
  
  	// citesc elementele
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
  
    // afisez numarul cautat
    printf("%d\n", count_primes(n, v));
  
    return 0;
}