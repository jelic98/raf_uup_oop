#include <stdio.h>

#define SIZE 100

int main() {
	int n;

	scanf("%d", &n);

	int b[SIZE] = {0};

	int a[SIZE][SIZE];

	int i, j, max, rpt = 0;

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);

			b[a[i][j]]++;

			if(b[a[i][j]] > 1) {
				rpt = 1;	
			}

			if(max < a[i][j]) {
				max = a[i][j];
			}
		}
	}

	if(rpt) {
		printf("matrica ima elemente koji se ponavljaju\n");

		for(i = 1; i <= max; i++) {
			if(b[i] > 1) {
				printf("%d - %d puta\n", i, b[i]);
			}
		}
	}else {
		printf("matrica nema elemente koji se ponavljaju\n");
	}
}
