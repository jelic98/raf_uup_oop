#include <stdio.h>

int getlow(char);

int main() {
	char curr, prev = '\0';

	while((curr = getlow(getchar())) != EOF && curr != '\n') {
		if(curr >= 'a' && curr <= 'z' && (prev < 'a' || prev > 'z')) {
			prev = curr;
			continue;
		}
		
		printf("%c", curr);

		prev = curr;
	}

	printf("\n");

	return 0;	
}

int getlow(char c) {
	if(c >= 'A' && c <= 'Z') {
		c += 32;
	}

	return c;
}
