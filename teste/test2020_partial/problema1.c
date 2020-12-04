#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned long lower_fib(unsigned long n, unsigned long *urm, unsigned long *nr)
{
	*nr = 1;
	if(n == 1)
    	return 1;

    unsigned long a = 1, b = 1, c = 0;
 	while (c <= n) {
 		c = a + b;
 		a = b;
 		b = c;
 		(*nr)++;
 	}

 	*urm = b - a;
 	return a;
}

void fibo_print(unsigned long n) {
  unsigned long prim, urm, aux, nr;
  
  /*printf("%ld\n", lower_fib(n, &urm));
  printf("%ld\n", urm);*/

  prim = lower_fib(n, &urm, &nr);

  while (n > 0) {
  	if (n >= prim) {
  		printf("1");
  		n -= prim;
  	} else
  		printf("0");

  	aux = prim;
  	prim = urm;
  	urm = aux - prim;
  	nr--;
  }
  while (nr--)
  	printf("0");
  printf("\n");
}

int main(void) {
  int n;
  unsigned long x;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%lu", &x);
    fibo_print(x);
  }
  
  return 0;
}

