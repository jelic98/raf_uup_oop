#include <stdio.h>
#define HI 1
#define LO -1

int main() {
	int state = LO, count = 0;
	char c;

	while((c = getchar()) != EOF && c != '\n') {
		if(count++ == 2) {
			state *= -1;
			count = 1;
		}
		
		if(state == HI) {
			printf("%c", c - 32);
		}else {
			printf("%c", c);
		}
	}

	printf("\n");

	return 0;
}
