#include <stdio.h>

int main() {
	int n, i, j, x;

	scanf("%d", &n);

	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			x = i / 2 + i % 2;

			if(i % 2 == 0) {
				printf("%d", x - j % 2 + 1);
			}else {
				x += j - 1;

				if(x > n) {
					x %= n;
				}

				printf("%d", x);
			}
		}

		printf("\n");
	}

	return 0;	
}
