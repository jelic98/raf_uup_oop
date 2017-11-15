#include <stdio.h>

#define HI 1

int main() {
	int state = HI;
	char curr, prev = '\0';

	while((curr = getchar()) != EOF && curr != '\n') {
		if(curr != prev) {
			state *= -1;
		}

		if(state == HI) {
			printf("%c", curr - 32);
		}else {
			printf("%c", curr);
		}
		
		prev = curr;
	}

	printf("\n");

	return 0;
}
