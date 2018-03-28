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
		a[i++][j] = n % 10;
	
		n /= 10;	
	}
	
	n = i;

	for(i = 0; i < n / 2; i++) {
		p = a[i][j];
		a[i][j] = a[n - i - 1][j];
		a[n - i - 1][j] = p;
	}

	for(j = 1; j < n; j++) {
		for(i = 0; i < n; i++) {
			if(i == 0) {
				a[i][j] = (a[n - 1][j - 1] * a[i][j - 1] * a[i + 1][j - 1]) % 10;
			}else if(i == n - 1) {
				a[i][j] = (a[i - 1][j - 1] * a[i][j - 1] * a[0][j - 1]) % 10;
			}else {
				a[i][j] = (a[i - 1][j - 1] * a[i][j - 1] * a[i + 1][j - 1]) % 10;
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
