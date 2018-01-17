#include <stdio.h>

#define SIZE 100

void modifikuj(int[SIZE][SIZE], int);
int minimum(int, int);

int main() {
	int a[SIZE][SIZE];
	int i, n, j;

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	modifikuj(a, n);
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%3d", a[i][j]);
		}

		printf("\n");
	}

	return 0;
}

void modifikuj(int a[SIZE][SIZE], int n) {
	int row[SIZE], col[SIZE], i, j, min;

	for(i = 0; i < n; i++) {
		min = a[i][0];

		for(j = 1; j < n; j++) {
			if(a[i][j] < min) {
				min = a[i][j];
			}
		}

		row[i] = min;
	}

	for(j = 0; j < n; j++) {
		min = a[0][j];

		for(i = 1; i < n; i++) {
			if(a[i][j] < min) {
				min = a[i][j];
			}
		}

		col[j] = min;
	}

	

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			a[i][j] = minimum(row[i], col[j]);
		}
	}
}

int minimum(int a, int b) {
	if(a < b) {
		return a;
	}

	return b;
}
