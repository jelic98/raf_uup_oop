#include <stdio.h>

int main() {
	int n, i, j;

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		for(j = 0; j < 2 * n; j++) {
			if(j >= n - i && j <= n + i) {
				if(i % 2 == 0) {
					printf("+");
				}else {
					printf("-");
				}	
			}else {
				printf(" ");	
			}
		}	

		printf("\n");
	}

	return 0;	
}
