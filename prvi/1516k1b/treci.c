#include <stdio.h>

int main() {
	int n, i, j, count2, count = 0;

	scanf("%d", &n);

	for(i = 0; i < n / 2 + n % 2; i++) {
		count2 = 0;

		for(j = 0; j < n; j++) {
			if(j >= n / 2 - i && count2 < 2) {
				printf("%d", ++count);
				
				count %= 9;
				count2++;
			}else {
				printf("-");	
			}	
		}

		printf("\n");	
	}

	for(i = n / 2 - 1; i >= 0; i--) {
		count2 = 0;

		for(j = 0; j < n; j++) {
			if(j >= n / 2 - i && count2 < 2) {
				printf("%d", ++count);

				count %= 9;
				count2++;
			}else {
				printf("-");	
			}	
		}

		printf("\n");	
	}

	return 0;	
}
