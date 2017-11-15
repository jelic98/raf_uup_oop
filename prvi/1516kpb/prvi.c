#include <stdio.h>

int test(int);

int main() {
	int res = 1, min, max;

	scanf("%d%d", &min, &max);

	while(min++ < max) {
		if(test(min)) {
			res *= min;
			printf("%d\n", min);
		}	
	}

	printf("%d\n", res);

	return 0;	
}

int test(int n) {
	int count = 0;

	while(n > 0) {
		count++;	
		n /= 10;
	}

	return count % 2 == 0;	
}
