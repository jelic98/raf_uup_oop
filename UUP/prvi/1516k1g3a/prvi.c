#include <stdio.h>

int pom(int);

int main() {
	int n, sum = 0;

	while(1) {
		scanf("%d", &n);

		if(n == 0) {
			break;	
		}	

		printf("%d\n", pom(n));

		sum += pom(n);
	}

	printf("%d\n", sum);

	return 0;
}

int pom(int n) {
	int m, fact = 1;

	if((n > 0 && n < 100) || (n < 0 && n > -100)) {
		return 0;	
	}

	n /= 10;
	m = n;

	while(n > 0) {
		fact *= 10;
		n /= 10;
	}

	m %= fact / 10;

	return m;
}
