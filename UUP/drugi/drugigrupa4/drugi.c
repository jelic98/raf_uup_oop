#include <stdio.h>

#define SIZE 100

void modifikuj(int[SIZE][SIZE], int[SIZE][SIZE], int);

int main() {
	int b[SIZE][SIZE], a[SIZE][SIZE] = {
	{2, 3, 5, 2, 1},
	{3, 5, 1, 2, 1},
	{1, 2, 2, 5, 3},
	{7, 3, 2, 5, 4},
	{1, 3, 3, 1, 5}
	};

	int i, n, j;

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	modifikuj(a, b, n);
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%3d", b[i][j]);
		}

		printf("\n");
	}

	return 0;
}

void modifikuj(int a[SIZE][SIZE], int b[SIZE][SIZE], int n) {
	int i, j;

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(j == 0) {
				b[i][j] = a[i][j + 1];	
			}else if(j == n - 1) {
				b[i][j] = a[i][j - 1];
			}else {
				b[i][j] = a[i][j - 1] + a[i][j + 1];	
			}
		}
	}
}
