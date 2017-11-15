#include <stdio.h>

int main() {
	int n, i, j;

	scanf("%d", &n);

	for(i = 1; i <= n / 2 + n % 2 ; i++) {
		for(j = 1; j <= n; j++) {
			if(j >= i) {
				printf("%d", i);			
			}else {
				printf("%d", j);	
			}
		}	
	
		printf("\n");
	}

	for(i = n / 2; i >= 1; i--) {
		for(j = 1; j <= n; j++) {
			if(j >= i) {
				printf("%d", i);			
			}else {
				printf("%d", j);	
			}
		}	
	
		printf("\n");
	}

	return 0;	
}
