#include <stdio.h>

int main() {
	int num = 1;
	char curr, prev = '\0';

	while((curr = getchar()) != EOF) {
		if(curr >= 'A' && curr <= 'Z') {
			curr += 32;
		}

		if(curr == prev) {
			num++;
		}else {
			if(prev != '\0') {
				printf("%c%d", prev, num);
			}

			num = 1;

			if(curr == '\n') {
				break;	
			}
		}

		prev = curr;
	}

	printf("\n");

	return 0;
}
