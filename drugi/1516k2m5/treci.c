#include <stdio.h>

#define PLUS 0
#define MINUS 1

int main() {
	char* s;
	int n = 0, res = 0, op = PLUS;

	scanf("%s", s);

	while(*s) {
		if(*s >= '0' && *s <= '9') {
			n *= 10;
			n += *s - '0';
		}else {
			if(op == PLUS) {
				res += n;	
			}else if(op == MINUS) {
				res -= n;
			}
			
			if(*s == '+') {
				op = PLUS;
			}else if(*s == '-') {
				op = MINUS;
			}

			n = 0;
		}

		s++;
	}
	
	if(op == PLUS) {
		res += n;	
	}else if(op == MINUS) {
		res -= n;
	}

	printf("%d\n", res);

	return 0;
}
