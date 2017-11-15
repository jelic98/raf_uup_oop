#include <stdio.h>

int main() {
	int count = 1;
	char c;

	while((c = getchar()) != EOF && c != '\n') {
		printf("%d", c - '0' - count++);
	}

	printf("\n");

	return 0;
}
