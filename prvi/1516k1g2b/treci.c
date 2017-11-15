#include <stdio.h>

int main() {
	int n, i, j, x;

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		for(j = 1; j <= i / 2; j++)
			printf("-");

		x = j;

		for(j = 0; j < n - i; j++)
			printf("%d", x++);

		for(j = x; j <= n; j++)
			printf("-");

		printf("\n");	
	}

	return 0;
}
