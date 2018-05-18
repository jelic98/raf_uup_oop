#include <stdio.h>

#define SIZE 100

void modifikuj(int[SIZE][SIZE], int[SIZE][SIZE], int);

int main() {
	int b[SIZE][SIZE], a[SIZE][SIZE];
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
