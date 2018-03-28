#include <stdio.h>

#define SIZE 100

int main() {
	int n, p, d;

	scanf("%d%d%d", &d, &p, &n);

	int a[SIZE][SIZE], b[SIZE];

	int i = 0, j;
	
	while(d) {
		b[i++] = d % 10;
		d /= 10;
	}

	int count = -1, m = i;

	for(i = 0; i < m / 2; i++) {
		int p = b[i];
		b[i] = b[m - i - 1];
		b[m - i - 1] = p;
	}

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(++count / p >= m) {
				count = 0;
			}

			a[i][j] = b[count / p];
		}	
	}

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%3d", a[i][j]);
		}

		printf("\n");
	}

	return 0;
}
