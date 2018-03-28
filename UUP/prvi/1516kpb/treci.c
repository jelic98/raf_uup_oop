#include <stdio.h>

int main() {
	int n, i, j, count = 0, mod;

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			mod = ++count % 4;

			if(mod == 1 || mod == 2) {
				printf("<");
			}else {
				printf(">");
			}
		}
	
		printf("\n");	
	}

	return 0;	
}
