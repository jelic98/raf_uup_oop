#include <stdio.h>

int test(int);

int main() {
	int min, max, res = 1;

	scanf("%d%d", &min, &max);

	while(min++ <= max) {
		if(test(min)) {
			res += min;
		}
	}

	printf("%d\n", res);

	return 0;
}

int test(int n) {
	int m, dig, res = 1;
	
	m = n;

	while(n > 0) {
		dig = n % 10;

		if(dig % 2 != 0) {
			res *= dig; 
		}

		n /= 10;
	}

	return res < 15;	
}
