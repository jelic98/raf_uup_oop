#include <stdio.h>

int test(int);

int main() {
	int n, sum = 0;

	while(1) {
		scanf("%d", &n);

		if(n == 0) {
			break;
		}

		sum += test(n);
	}

	printf("%d\n", sum);

	return 0;
}

int test(int n) {
	int m = 0, fact = 1;

	while(n > 0) {
		if((n % 10) % 2 != 0) {
			m += (n % 10) * fact;
			fact *= 10;
		}

		n /= 10;
	}

	return m;
}
