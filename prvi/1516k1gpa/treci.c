#include <stdio.h>

int main() {
	int n, i, j, count = 0;

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(count++ < 3) {
				printf("/");
			}else {
				printf("\\");
				
				if(count == 6) {
					count = 0;
				}
			}
		}

		printf("\n");	
	}

	return 0;
}
