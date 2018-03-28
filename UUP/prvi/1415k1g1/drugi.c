#include <stdio.h>

int main() {
	char c, curr, prev = '\0';

	while((c = getchar()) != EOF && c != '\n') {
		curr = c;
	
		if(curr >= 'a' && curr <= 'z') {
			curr -= 32;
		}

		if(curr != prev + 1) {
			printf("%c", c);
		}

		prev = curr;
	}

	printf("\n");

	return 0;
}
