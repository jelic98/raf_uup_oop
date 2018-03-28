#include <stdio.h>

#define SIZE 100

int main() {
	int n;

	scanf("%d", &n);

	int a[SIZE][SIZE];

	int i, j, up, down;
	
	up = 1;
	down = n * (n - 1);

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(j < i) {
				a[i][j] = up++;
			}else if(j > i) {
				a[i][j] = down--;
			}else {
				a[i][j] = 0;	
			}
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
