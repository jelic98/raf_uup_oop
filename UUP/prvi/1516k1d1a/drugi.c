#include <stdio.h>

int main() {
	char c;

	while((c = getchar()) != EOF && c != '\n') {
		if(c >= '0' && c <= '9') {
			switch(c) {
				case '8':
					c = '0';
					break;
				case '9':
					c = '1';
					break;
				default:
					c += 2;
					break;

			}
		}

		printf("%c", c);
	}

	printf("\n");

	return 0;
}
