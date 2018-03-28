#include <stdio.h>

#define SIZE 100

void ispis(char[][SIZE], int, int);

int main() {
	char a[SIZE][SIZE];
	int i, j, m, n, x, y;

	scanf("%d%d%d%d", &n, &m, &x, &y);
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			if(j - i == x - y || j + i == x + y) {
				a[i][j] = 2;
			}else {	
				a[i][j] = 1;
			}
		}
	}

	ispis(a, n, m);

	return 0;
}

void ispis(char a[][SIZE], int n, int m) {
	int i, j;

	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			printf("%2d", a[i][j]);
		}

		printf("\n");
	}
}
