#include <stdio.h>

int pom(int);

int main() {
	int min, max, sum = 0;

	scanf("%d%d", &min, &max);

	while(min++ <= max) {
		sum += pom(min - 1) * (min - 1);
	}

	printf("%d\n", sum);

	return 0;
}

int pom(int n) {
	int count = 0;

	while(n > 0) {
		count++;
		n /= 10;	
	}

	return count % 2 == 0;	
}
