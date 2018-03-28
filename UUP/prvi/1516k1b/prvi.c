#include <stdio.h>

int test(int);

int main() {
	int min, max, res = 1;

	scanf("%d%d", &min, &max);

	while(min++ <= max) {
		if(test(min - 1)) {
			res *= min - 1;
		}
	}

	printf("%d\n", res);

	return 0;	
}

int test(int n) {
	int res = 1;
	
	while(n > 100) {
		n /= 10;
	}

	res = (n % 10) * (n / 10);
	
	return res % 2 != 0;	
}
