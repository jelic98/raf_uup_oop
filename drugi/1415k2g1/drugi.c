#include <stdio.h>

#define SIZE 100

void ispis(int[][SIZE], int);

int main() {
	int a[SIZE][SIZE];
	int i, j, n;

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(i < n - j) {
				a[i][j] = i + 1;
			}else {
				a[i][j] = n - j;
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
