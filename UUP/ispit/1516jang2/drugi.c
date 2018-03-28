#include <stdio.h>

#define SIZE 100

int main() {
	char s[SIZE];
	
	gets(s);

	char *p = s;

	int f = 1, n = 0;
	int max = 0;

	while(*p) {
		if(*p == ' ') {
			if(n > max) {
				max = n;
			}
			
			f = 1;
			n = 0;
		}else if(*p != '5') {
			n += (*p - '0') * f;
			f *= 10;
		}

		p++;
	}

	printf("%d\n", max);

	return 0;
}
