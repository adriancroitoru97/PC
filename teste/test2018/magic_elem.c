#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int get_magic_element(int* v, int n) {
  int cnt[101] = {0};
  int max = -1, poz;

  for (int i = 0; i < n; ++i) {
      cnt[v[i]]++;
  }

  for (int i = 0; i < 101; ++i) {
      if (cnt[i] >= max) {
        max = cnt[i];
        poz = i;
      }
  }

  if (max > -1)
    return poz;
  
  return -1;
}

int main() {
  	int n, i;
  	int *v;
	scanf("%d", &n);
  	v = (int *) malloc(n * sizeof(int));
  	for (i = 0; i < n; ++i) {
    	scanf("%d", &v[i]);
    }
  	printf("%d\n", get_magic_element(v, n));
	return 0;
}