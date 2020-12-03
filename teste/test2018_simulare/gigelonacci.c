#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, p, q;

    scanf("%d %d %d", &n, &p, &q);

    int z = p ^ q;

    if (n == 0)
    	printf("%d\n", p);
    else if (n == 1)
    	printf("%d\n", q);
    else {
    	for (int i = 1; i < n; i++) {
    		z = p ^ q;
    		p = q;
    		q = z;
    	}
    	printf("%d\n", q);
    }

    return 0;
}							