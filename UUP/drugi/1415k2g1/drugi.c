#include <stdio.h>

#define SIZE 100

int a[SIZE][SIZE];

void popuni(int);
void ispis(int);

int main() {
	int n;

	scanf("%d", &n);

	popuni(n);

	ispis(n);

	return 0;
}

void popuni(int n) {
	int i, j;
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(i < n - j) {
				a[i][j] = i + 1;
			}else {
				a[i][j] = n - j;
			}
		}	
	}	
}

void ispis(int n) {
	int i, j;
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%d", a[i][j]);
		}	

		printf("\n");
	}	
}
