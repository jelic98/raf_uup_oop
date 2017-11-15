#include <stdio.h>

#define LO 0
#define HI 9

int main() {
	int n, i, j, x, y;

	scanf("%d", &n);

	x = LO;
	y = HI + 1;

	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			if((i + j) % 2 == 0) {
				x++;

				if(x > HI) {
					x = LO;
				}
				
				printf("%d ", x);
			}else {
				y--;

				if(y < LO) {
					y = HI;
				}
			
				printf("%d ", y);
			}
		}

		printf("\n");
	}

	return 0;
}
