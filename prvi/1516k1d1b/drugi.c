#include <stdio.h>

int invert(int);

int main() {
	int fresh = 1;
	char c;

	while((c = getchar()) != EOF && c != '\n') {
		printf((fresh) ? "%d" : "-%d", invert(c));
		fresh = 0;
	}

	printf("\n");

	return 0;	
}

int invert(int n) {
	int m = 0;

	while(n > 0) {
		m *= 10;
		m += n % 10;

		n /= 10;	
	}
	
	return m;	
}
