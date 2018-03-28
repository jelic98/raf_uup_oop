#include <stdio.h>

#define SIZE 100

int main() {
	int n, m;

	scanf("%d%d", &n, &m);

	int a[SIZE][SIZE];

	int i, j;

	for(j = 0; j < m; j++) {
		int p;

		for(i = 0; i < n; i++) {
			if(j % 2) {
				if(i == 0) {
					a[i][j] = a[n - 1][j - 1];
					p = n - 1;
				}else {
					a[i][j] = a[i - 1][j] - p--;
				}
			}else {
				if(i == 0) {
					a[i][j] = p = 1;
				}else {
					a[i][j] = a[i - 1][j] + p++;
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
