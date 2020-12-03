#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	double perimeter = 0;
	int n;
	double x1, y1, x2, y2;
	double x0, y0;

	scanf("%d", &n);

	scanf("%lf %lf", &x0, &y0);
	x1 = x0; y1 = y0;
	for (int i = 0; i < n - 1; i++) {
		scanf("%lf %lf", &x2, &y2);
		perimeter += sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		x1 = x2; y1 = y2;
	}
	perimeter += sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));

	printf("%lf\n", perimeter);
    
    return 0;
}