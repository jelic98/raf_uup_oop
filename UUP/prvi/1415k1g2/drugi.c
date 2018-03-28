#include <stdio.h>

int main() {
	char c, prev = '\0';

	while((c = getchar()) != EOF && c != '\n') {
		if(c == prev + 1 || c == prev + 33) {
			c -= 32;	
		}

		printf("%c", c);
	
		prev = c;
	}

	printf("\n");
	
	return 0;	
}
