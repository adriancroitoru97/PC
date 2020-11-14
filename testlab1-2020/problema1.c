//Adrian-Valeriu Croitoru, 312CA

#include <stdio.h>


int hash(int x) {
	int h;

    if (x < 0) {
    	x = -x;
    }

    if (x <= 9) {
    	return 4 * x;
    }

    h = x % 10 * 2;
    x /= 10;
    while (x > 9) {
    	h = h + x % 10;
    	x /= 10;
    }

    h = h + 2 * x;

    return h;
}



int main() {
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        printf("%d\n", hash(x));
    }

    return 0;
}