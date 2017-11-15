#include <stdio.h>

int main() {
	int n, i, j;

	scanf("%d", &n);

	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			if(i % 2 != 0) {
				if(j != n - i / 2) {
					printf("%c", 'A' + i / 2 + i % 2 - 1);
				}else {
					printf("%c", 'A' + i / 2 + i % 2);
				}
			}else {
				if(j % 2 == 0) {
					printf("%c", 'A' + i / 2 + i % 2);
				}else {
					printf("%c", 'A' + i / 2 + i % 2 - 1);
				}	
			}
		}

		printf("\n");	
	}

	return 0;
}
