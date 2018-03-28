#include <stdio.h>

int main() {
	int n, i, j, count;

	scanf("%d", &n);

	for(i = 1; i <= n; i++) {
		count = n - i;

		for(j = 1; j <= n; j++) {
			if(j > count / 2 + count % 2 && j <= n - count / 2) {
				printf("%c", 'A' + j - 1);
			}else {
				printf("-");	
			}
		}

		printf("\n");
	}

	return 0;	
}
