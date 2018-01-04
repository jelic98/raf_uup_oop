#include <stdio.h>

#define SIZE 100

int main() {
	char s[SIZE];
	
	gets(s);
	
	char *p = s;

	int n = 0;
	int max = 0;

	while(*p) {
		if(*p == ' ') {
			if(n > max) {
				max = n;
			}
			
			n = 0;
		}else if(*p - '0' >= 3) {
			n *= 10;
			n += *p - '0';
		}

		p++;
	}

	printf("%d\n", max);

	return 0;
}
