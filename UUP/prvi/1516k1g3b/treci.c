#include <stdio.h>

int main() {
	int n, i, j;

	scanf("%d", &n);

	for(i = n - 1; i >= 0; i--) {
		for(j = 0; j < n / 2 + n % 2; j++) {
			if(j >= i) {
				printf("%c", 'A' + i);
			}else {
				printf("%c", 'A' + j);
			}
		}

		for(j = n / 2 - n % 2; j >= 0; j--) {
			if(j >= i) {
				printf("%c", 'A' + i);
			}else {
				printf("%c", 'A' + j);
			}
		}

		printf("\n");
	}

	return 0;
}
