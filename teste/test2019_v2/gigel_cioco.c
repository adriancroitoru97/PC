#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 1000


void print_ciocogame2(int n, int *x, int target) {
    while (1) {
    	int poz_min, min = target;
    	int ver = 0;
    	for (int i = 0; i < n; i++) {
    		if (x[i] < target && x[i] <= min) {
    			poz_min = i;
    			min = x[i];
    			ver = 1;
    		}
    	}

    	if (!ver)
    		break;

    	if (x[poz_min - 1] >= x[poz_min + 1])
    		x[poz_min - 1] += x[poz_min];
    	else 
    		x[poz_min + 1] += x[poz_min];

    	n--;
    	for (int i = poz_min; i < n; i++) {
    		x[i] = x[i + 1];
    	}
    }

    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

int main() {
    int n, x[NMAX] = {0}, target;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x[i]);
    }
    scanf("%d", &target);
    print_ciocogame2(n, x, target);
    return 0;
}
