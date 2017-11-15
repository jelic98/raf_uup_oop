#include <stdio.h>

int pom(int);

int main() {
	int n, sum = 0;

	while(1) {
		scanf("%d", &n);

		if(n == 0) {
			break;
		}

		if(pom(n) % 2 != 0) {
			sum += pom(n);	
		}
	}

	printf("%d\n", sum);

	return 0;
}

int pom(int n) {
	int count = 0;

	while(n > 0) {
		if((n % 10) % 2 == 0) {
			count++;
		}

		n /= 10;
	}

	return count;
}
