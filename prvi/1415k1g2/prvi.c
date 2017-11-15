#include <stdio.h>

int test(int, int);

int main() {
	int min, max, t, res = 1;

	scanf("%d%d%d", &min, &max, &t);

	while(min++ <= max) {
		if(test(min - 1, t)) {
			res *= min - 1;	
		}	
	}

	printf("%d\n", res);

	return 0;	
}

int test(int n, int t) {
	while(n > 0) {
		if(n % 10 == t) {
			return 1;	
		}	

		n /= 10;
	}

	return 0;	
}
