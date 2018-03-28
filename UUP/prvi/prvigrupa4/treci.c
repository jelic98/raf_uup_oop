#include <stdio.h>

int main() {
	int n, i, j, num;

	scanf("%d", &n);

	for(i = 1; i <= n; i++) {
		if(i % 2 == 0) {
			num = i;	
		}else {
			num = n - i + 1;
		}

		for(j = 1; j <= n; j++) {
			if(j == num) {
				printf("%d", i + 1);
			}else {
				printf("%d", i);
			}

		}

		printf("\n");
	}

	return 0;
}
