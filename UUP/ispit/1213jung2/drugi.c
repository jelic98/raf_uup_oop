#include <stdio.h>

#define SIZE 100

int main() {
	char s[SIZE];

	scanf("%s", s);

	char a[SIZE][SIZE];

	int n, i, j = 0;

	while(s[j]) {
		a[0][j] = s[j];
		j++;
	}

	n = j;
	
	for(i = 1; i < n; i++) {
		for(j = 0; j < n; j++) {
			a[i][j] = a[i - 1][(j == n - 1) ? 0 : j + 1];
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
