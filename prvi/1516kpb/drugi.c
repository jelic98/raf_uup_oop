#include <stdio.h>

#define NUM 1
#define CHR -1

int main() {
	int state, n = 0;
	char curr, prev = '\0';

	while((curr = getchar()) != EOF) {
		if(curr >= '0' && curr <= '9') {
			state = NUM;
		}else {
			state = CHR;	
		}

		if(state == NUM) {
			n *= 10;
			n += curr - '0';
		}else {
			if(n / 10 != 0) {
				printf("%d", n / 10);
				n = 0;
			}

			if(curr == '\n') {
				break;	
			}else {
				printf("%c", curr);
			}
		}
	
		prev = curr;
	}

	printf("\n");

	return 0;	
}
