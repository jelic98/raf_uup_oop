#include <stdio.h>

int main() {
	int n = 0;
	char c;
	
	while((c = getchar()) != EOF && c != '\n') {
		if(c >= '0' && c <= '9') {
			n *= 10;
			n += c - '0';
		}else {
			while(n-- > 0) {
				printf("%c", c);		
			}

			n = 0;
		}
	}

	printf("\n");

	return 0;	
}
