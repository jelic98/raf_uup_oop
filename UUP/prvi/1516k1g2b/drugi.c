#include <stdio.h>

int main() {
	int num;
	char c, slovo;

	while((c = getchar()) != EOF) {
		if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
			slovo = c;
			num = 0;
		}else if(c >= '0' && c <= '9') {
			num *= 10;
			num += c - '0';
		}else {
			while(num-- > 0) {
				printf("%c", slovo);
			}

			printf("%c", c);
			
			if(c == '\n') {
				break;	
			}
		}		
	}

	return 0;	
}
