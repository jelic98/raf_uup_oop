#include <stdio.h>

int main() {
	int first = 0, second = 0, third = 0;
	char c;

	while((c = getchar()) != EOF && c != '\n') {
		
		if(c >= '0' && c <= '9') {
			first = second;
			second = third;
			third = c - '0';
		}
	}

	printf("%d%d%d\n", first, second, third);

	return 0;	
}
