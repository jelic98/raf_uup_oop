#include <stdio.h>

int main() {
	int count = 0;
	char curr, prev = '\0';

	while((curr = getchar()) != EOF && curr != '\n') {
		if(prev == curr) {
			count++;	
		}else {
			count = 0;	
		}
		
		if(count < 2) {
			printf("%c", curr);
		}

		prev = curr;
	}

	printf("\n");

	return 0;
}
