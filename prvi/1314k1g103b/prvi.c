#include <stdio.h>

int fun(int);

int main() {
	int n, sum = 0;

	while(1) {
		scanf("%d", &n);

		if(n == 0) {
			break;
		}

		sum += fun(n);
	}

	printf("%d\n", sum);

	return 0;
}

int fun(int n) {
	if(n / 10 == 0) {
		return 0;
	}

	while(n / 100 != 0) {
		n /= 10;
	}

	return n % 10;
}
