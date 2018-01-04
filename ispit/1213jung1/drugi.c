#include <stdio.h>

#define SIZE 100

int main() {
	int n;

	scanf("%d", &n);

	int a[SIZE][SIZE];

	int i, j = 0;

	while(n) {
		a[0][j++] = n % 10;
		n /= 10;
	}

	n = j;
	
	for(j = 0; j < n / 2; j++) {
		int p = a[0][j];
		a[0][j] = a[0][n - 1 - j];
		a[0][n - 1 - j] = p;
	}
	
	for(i = 1; i < n; i++) {
		for(j = 0; j < n; j++) {
			a[i][j] = a[i - 1][(j == n - 1) ? 0 : j + 1];
		}	
	}

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%3d", a[i][j]);
		}

		printf("\n");
	}

	return 0;
}
