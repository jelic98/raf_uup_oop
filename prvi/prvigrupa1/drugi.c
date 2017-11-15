#include <stdio.h>

int main() {
	int res = 0, num = 0;
	char c, op = '+';

	while((c = getchar()) != EOF && c != '\n') {
		if(c >= '0' && c <= '9') {	
			num *= 10;
			num += c - '0';
		}else {
			if(op == '+') {
				res += num;
			}else if(op == '-') {
				res -= num;
			}
			
			num = 0;
			op = c;
		}
	}
	
	if(op == '+') {
		res += num;
	}else if(op == '-') {
		res -= num;
	}

	printf("%d\n", res);

	return 0;	
}
