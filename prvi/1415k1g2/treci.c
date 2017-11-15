#include <stdio.h>

int main() {
	int n, i, j, bound, flag;

	scanf("%d", &n);

	bound = n / 2;

	for(i = 0; 
	(i < bound && !flag) ? i < bound : (flag = 1, i >= 0); 
	(i < bound && !flag) ? i++ : i--) {
		for(j = 0; j < n; j++) {	
			if(j >= bound - i && j <= bound + i) {
				if(i % 2 == 0) {
					printf(">");
				}else {
					printf("<");	
				}
			}else {
				printf("-");	
			}
		}

		printf("\n");
	}

	return 0;	
}
