#include <stdio.h>

int pom(int);

int main() {
	int n, sum = 0;

	while(1) {
		scanf("%d", &n);

		if(n == 0) {
			break;	
		}

		sum += pom(n) * n;
	}

	printf("%d\n", sum);

	return 0;	
}

int pom(int n1) {
	int n2 = n1, m = 0;

	while(n1 > 0) {
		m *= 10;
		m += n1 % 10;

		n1 /= 10;	
	}

	return n2 > m;	
}
