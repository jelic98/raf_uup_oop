#include <stdio.h>

int main() {
	char c, i;

	i = 1;

	while((c = getchar()) != EOF && c != '\n') {
		printf("%c", c + i++);
	}

	printf("\n");

	return 0;	
}
