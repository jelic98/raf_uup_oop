#include <stdio.h>

#define SIZE 100

int main() {
	int n;

	scanf("%d", &n);

	int a[SIZE][SIZE];

	int i, j, up, down;
	
	up = 'A';
	down = 'A' + n * (n - 1) - 1;

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(j < i) {
				a[i][j] = up++;
			}else if(j > i) {
				a[i][j] = down--;
			}else {
				a[i][j] = ' ';	
			}
		}	
	}

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%3c", a[i][j]);
		}

		printf("\n");
	}

	return 0;
}
