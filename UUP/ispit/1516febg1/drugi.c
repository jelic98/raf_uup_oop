#include <stdio.h>

#define SIZE 100

int main() {
	int n, m;

	scanf("%d%d", &n, &m);

	int a[SIZE][SIZE];

	int i, j;

	for(i = 0; i < n; i++) {
		int p;

		for(j = 0; j < m; j++) {
			if(i % 2) {
				if(j == 0) {
					a[i][j] = a[i - 1][m - 1];
					p = m - 1;
				}else {
					a[i][j] = a[i][j - 1] - p--;
				}
			}else {
				if(j == 0) {
					a[i][j] = p = 1;
				}else {
					a[i][j] = a[i][j - 1] + p++;
				}
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
