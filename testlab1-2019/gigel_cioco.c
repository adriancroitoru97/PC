//Copyright Adrian Croitoru

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_ciocogame1(int a, int b, int target) {
    int ver = 1;
    int n = 2, v[1001];
    int i;
    int max, poz_max;

    v[0] = a;
    v[1] = b;

    while (ver) {
    	ver = 0;
    	max = target;

    	for (i = 0; i < n; i++) {
    		if (v[i] > max) {
    			max = v[i];
    			poz_max = i;
    			ver = 1;
    		} 
    	}

    	if (ver) {
    		n++;

    		for(i = n - 1; i > poz_max + 1; i--) {
    			v[i] = v[i - 1];
    		}

    		v[poz_max] = max / 2;
    		v[poz_max + 1] = max / 2;

    		if(max % 2 == 1) {
    			v[poz_max]++;
    		}
    	}
    }

    printf("%d\n", n);

    for (i = 0; i < n; i++) {
    	printf("%d ", v[i]);
    }

}


int main() {
    int a, b, target;
    scanf("%d%d%d", &a, &b, &target);
    print_ciocogame1(a, b, target);
    return 0;
}

