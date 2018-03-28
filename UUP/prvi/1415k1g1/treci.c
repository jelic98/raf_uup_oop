#include <stdio.h>

int main() {
	int n, i, j;

	scanf("%d", &n);

	for(i = 0; i < n / 2; i++) {
		for(j = 0; j < n; j++) {
			if(j < i || j >= n - i) {
				printf("-");	
			}else {
				if(i % 2 == 0) {	
					printf("<");
				}else {
					printf(">");
				}
			}
		}

		printf("\n");	
	}

	for(i = n / 2; i >= 0; i--) {
		for(j = 0; j < n; j++) {
			if(j < i || j >= n - i) {
				printf("-");	
			}else {
				if(i % 2 == 0) {	
					printf("<");
				}else {
					printf(">");
				}
			}
		}

		printf("\n");	
	}

	return 0;	
}
