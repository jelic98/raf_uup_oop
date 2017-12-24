#include <stdio.h>

#define SIZE 100

void ispis(char[][SIZE], int, int);

int main() {
	char a[SIZE][SIZE];
	int i, j, n, m, p, diff;

	scanf("%d%d%d", &n, &m, &p);

	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			diff = j - i;

			if(diff >= p) {
				diff %= p;	
			}else if(diff < 0) {
				diff = p + diff;
			}
				diff = (p + diff) % p;

			a[i][j] = 'A' + diff;
		}
	}

	ispis(a, n, m);

	return 0;
}

void ispis(char a[][SIZE], int n, int m) {
	int i, j;

	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			printf("%2c", a[i][j]);	
		}	

		printf("\n");
	}
}
