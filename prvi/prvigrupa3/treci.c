#include <stdio.h>

int main() {
	int n, i, j;

	scanf("%d", &n);

	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			if(i % 2 != 0) {
				printf("%d", i);
			}else {
				if(j % 4 == 1 || j % 4 == 2) {	
					printf("%d", i);
				}else {
					printf("%d", i + 2);
				}
			}
		}

		printf("\n");	
	}

	return 0;
}
