#include <stdio.h>

int main() {	
	int res = 1, num = 0;
	char c;

	while((c = getchar()) != EOF) {
		if(c >= '0' && c <= '9') {
			num *= 10;
			num += c - '0';
		}else {
			if(num > 10 && num < 100) {
				res *= num;
			}

			num = 0;

			if(c == '\n') {
				break;	
			}

			printf("%c", c);	
		}
	}

	printf("%d\n", res);

	return 0;
}
