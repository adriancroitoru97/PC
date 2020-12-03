//Copyright Adrian Croitoru

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int x;

	scanf("%d", &x);

	while(x > 1) {
		printf("%d ", x);

		if(x % 2 == 0) {
			x--;
		} else {
			x = x / 2 + 1;
		}
	}

	printf("1\n");

	return 0;
}

