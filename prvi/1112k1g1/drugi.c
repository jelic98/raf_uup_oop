#include <stdio.h>

int main() {
	char curr, prev = '\0';
	
	while((curr = getchar()) != EOF && curr != '\n') {
		if(curr != prev) {
			printf("%c", curr);
		}

		prev = curr;
	}

	printf("\n");

	return 0;	
}
