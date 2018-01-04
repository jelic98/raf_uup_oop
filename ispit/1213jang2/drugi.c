#include <stdio.h>

#define SIZE 100

int main() {
	int n, m;

	scanf("%d%d", &n, &m);

	int a[SIZE][SIZE];

	int i, j, up, down;

	up = 1;
	down = m * n;

	for(j = 0; j < m; j++) {
		for(i = 0; i < n; i++) {
			if((i + j) % 2) {
				a[i][j] = down--;	
			}else {
				a[i][j] = up++;	
			}
		}	
	}

	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) {
			printf("%3d", a[i][j]);
		}

		printf("\n");
	}

	return 0;
}
