#include <stdio.h>

int pom(int);

int main() {
	int min, max, sum = 0;

	scanf("%d%d", &min, &max);

	while(min++ <= max) {
		sum += pom(min) * min;
	}

	printf("%d\n", sum);

	return 0;
}

int pom(int n) {
	int sum = 0;

	while(n > 0) {
		if((n % 10) % 2 == 0) {
			sum += n % 10;	
		}

		n /= 10;	
	}

	return sum > 10;	
}
