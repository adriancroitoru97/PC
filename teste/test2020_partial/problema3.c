#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int sum_cif(int n)
{
	int nr = 0;
	while(n) {
		nr++;
		n /= 10;
	}
	return nr;
}

int main()
{
	int n, x;

	scanf("%d", &n);
	for (int i = 0 ; i < n; i++) {
		int d = 2;
		scanf("%d", &x);
		int d_x = x;
		int nr_cif = sum_cif(x);
		int nr_fact = 0;

		while (x > 1) {
			int ver = 0;
			while(x % d == 0)
        	{
            	++ver;
            	x /= d;
        	}

        	if (ver > 1)
        		nr_fact = nr_fact + sum_cif(d) + sum_cif(ver);
        	else if (ver == 1)
        		nr_fact = nr_fact + sum_cif(d);

       		d++;

        	if(x > 1 && d * d > x) {
            	d = x;
			}
		}

		//printf("%d %d\n", nr_cif, nr_fact);
		if(nr_cif > nr_fact)
			printf("%d ", d_x);
	}

	printf("\n");

    return 0;
}