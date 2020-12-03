#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    double x, y, cx = 0, cy = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    	scanf("%lf %lf", &x, &y);
    	cx += x;
    	cy += y;
    }

    printf("%.10lf %.10lf\n", cx / n, cy / n);
  
    return 0;
}