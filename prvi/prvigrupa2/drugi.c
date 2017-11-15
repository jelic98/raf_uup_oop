#include <stdio.h>

int main() {
	int num = 0, res = 1;
	char c, op = '*';

	while((c = getchar()) != 0) {
		if(c >= '0' && c <= '9') {
			num *= 10;
			num += c - '0';
		}else {
			if(num != 0) {
				if(op == '*') {
					res *= num;
				}else if(op == '/') {
					res /= num;
				}
			}
			
			if(c == '\n') {
				break;
			}

			num = 0;
			
			op = c;
		}
	}

	printf("%d\n", res);

	return 0;
}
