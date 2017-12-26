#include <stdio.h>

#define SIZE 100

void ispis(int[][SIZE], int);

int main() {
	int a[SIZE][SIZE];
	int i, j, n, p;

	scanf("%d", &n);

	i = 0;
	j = 0;

	while(n > 0) {
		a[i][j++] = n % 10;
	
		n /= 10;	
	}
	
	n = j;

	for(j = 0; j < n / 2; j++) {
		p = a[i][j];
		a[i][j] = a[i][n - j - 1];
		a[i][n - j - 1] = p;
	}

	for(i = 1; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(j == 0) {
				a[i][j] = (a[i - 1][n - 1] + a[i - 1][j] + a[i - 1][j + 1]) % 10;
			}else if(j == n - 1) {
				a[i][j] = (a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][0]) % 10;
			}else {
				a[i][j] = (a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1]) % 10;
			}
		}
	}

	ispis(a, n);

	return 0;
}

void ispis(int a[][SIZE], int n) {
	int i, j;

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%2d", a[i][j]);
		}

		printf("\n");
	}
}
