#include <stdio.h>

#define MUL 0
#define DIV 1

int main() {
	char* s;
	int n = 0, res = 1, op = MUL;

	scanf("%s", s);

	while(*s) {
		if(*s >= '0' && *s <= '9') {
			n *= 10;
			n += *s - '0';
		}else {
			if(op == MUL) {
				res *= n;	
			}else if(op == DIV) {
				res /= n;
			}
			
			if(*s == '*') {
				op = MUL;
			}else if(*s == '/') {
				op = DIV;
			}

			n = 0;
		}

		s++;
	}
	
	if(op == MUL) {
		res *= n;	
	}else if(op == DIV) {
		res /= n;
	}

	printf("%d\n", res);

	return 0;
}
