#include <stdio.h>

#define SIZE 100

void ispis(char[][SIZE], int);

int main() {
	char a[SIZE][SIZE];
	int i, j, n, count = 0, num = 1;

	scanf("%d", &n);
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(num == count++) {
				num++;
				count = 1;
			}

			a[i][j] = num;
		}
	}

	ispis(a, n);

	return 0;	
}

void ispis(char a[][SIZE], int n) {
	int i, j;

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%2d", a[i][j]);
		}

		printf("\n");
	}
}
