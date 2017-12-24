#include <stdio.h>

#define SIZE 100

void ispis(int[][SIZE], int);

int main() {
	int n, i, j, p, diff, count;
	int a[SIZE][SIZE];

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}	
	}

	count = 1;

	ispis(a, n);
	printf("\n");

	for(i = 1; i < n; i++) {
		int k = count;

		while(k-- > 0) {
			p = a[i][0];

			for(j = 1; j < n; j++) {
				a[i][j - 1] = a[i][j];
			}	

			a[i][n - 1] = p;
		}
	
		count = (count + 1) % n;
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
