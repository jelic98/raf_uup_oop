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
	while(n > 0) {
		if(n % 10 >= 5) {
			return 0;
		}

		n /= 10;
	}

	return 1;
}
