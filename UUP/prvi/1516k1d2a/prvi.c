#include <stdio.h>

int pom(int);

int main() {
	int n, res = 1;

	while(1) {
		scanf("%d", &n);

		if(n == 0) {
			break;	
		}
	
		if(pom(n)) {
			res *= pom(n); 
		}
	}

	printf("%d\n", res);

	return 0;
}

int pom(int n) {
	int m = 0, fact = 1;

	while(n > 0) {
		if(n % 10 >= 5) {
			m += fact * (n % 10);
			fact *= 10;
		}

		n /= 10;	
	}

	return m;
}
