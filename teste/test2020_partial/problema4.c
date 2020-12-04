#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n, v[5005] = {0};
    v[0] = 1;
    int cifre = 1;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++)
    {
        int t = 0;
        for(int j = 0 ; j < cifre ; j++)
        {
            int cif = t + 2 * v[j];
            v[j] = cif % 10;
            t = cif / 10;
        }

        while(t) {
        	v[++cifre] = t % 10;
        	t /= 10;
        }
    }

    for(int i = cifre - 1 ; i >= 0 ; i--)
        printf("%d", v[i]);
    printf("\n");
    
    return 0;
}
