#include <stdio.h>

int main() {
	int num = 0;
	char c;

	while((c = getchar()) != EOF) {
		if(c >= '0' && c <= '9') {
			num += c - '0';
		}else {
			if(num > 0) {
				printf("%d", num);
			}
			
			printf("%c", c);

			num = 0;
			
			if(c == '\n') {
				break;	
			}
		}
	}

	return 0;	
}
