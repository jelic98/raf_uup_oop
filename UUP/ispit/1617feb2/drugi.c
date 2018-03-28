#include <stdio.h>

#define SIZE 100

int main() {
	int n;

	scanf("%d", &n);

	int a[SIZE][SIZE];
	
	int i, j, max;

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	printf("Elementi koji se ponavljaju:\n");

	for(i = 0; i < n; i++) {
		int b[SIZE] = {0};

		for(j = 0; j < n; j++) {
			b[a[i][j]]++;

			if(max < a[i][j]) {
				max = a[i][j];
			}
		}
	
		for(j = 1; j <= max; j++) {
			if(b[j] > 1) {
				printf("%d - vrsta %d\n", j, i);
			}
		}
	}

	for(j = 0; j < n; j++) {
		int b[SIZE] = {0};

		for(i = 0; i < n; i++) {
			b[a[i][j]]++;

			if(max < a[i][j]) {
				max = a[i][j];
			}
		}
	
		for(i = 1; i <= max; i++) {
			if(b[i] > 1) {
				printf("%d - kolona %d\n", i, j);
			}
		}
	}

	return 0;
}
