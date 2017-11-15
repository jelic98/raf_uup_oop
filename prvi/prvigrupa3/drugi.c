#include <stdio.h>

int main() {
	int num = 1;
	char c, prev = '\0';

	while((c = getchar()) != EOF) {
		if(c >= 'A' && c <= 'Z') {
			c += 32;
		}

		if(c == prev) {
			num++;
		}else {
			if(prev != '\0') {
				printf("%d%c", num, prev);
			}

			if(c == '\n') {
				break;	
			}

			num = 1;
		}

		prev = c;
	}

	printf("\n");

	return 0;
}
