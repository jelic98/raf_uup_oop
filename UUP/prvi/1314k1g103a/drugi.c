#include <stdio.h>

int main() {
	char curr, prev = '\0';

	while((curr = getchar()) != EOF && curr != '\n') {
		if(curr >= '0' && curr <= '9' && (prev < '0' || prev > '9')) {
			prev = curr;
			continue;
		}
		
		printf("%c", curr);

		prev = curr;
	}

	printf("\n");

	return 0;	
}
