#include <stdio.h>

int main() {
	int n, i, j, countA = 0, countZ = 0;
	char c;

	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if((i + j) % 2 == 0) {
				c = 'A' + countA++;	
			}else {
				c = 'Z' - countZ++;	

				if(c < 'O') {
					c += 12;
					countA = 0;
					countZ = 1; 
				}
			}

			printf("%c", c);
		}

		printf("\n");	
	}

	return 0;	
}
