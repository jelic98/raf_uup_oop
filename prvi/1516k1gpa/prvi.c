#include <stdio.h>

int pom(int);

int main() {
	int res, i, min, max;

	scanf("%d%d", &min, &max);

	res = 0;

	for(i = min; i < max; i++) {
		res += pom(i) * i;
	}

	printf("%d\n", res);

	return 0;	
}

int pom(int n) {
	while(n > 0) {
		if((n % 10) % 2 != 0) {
			return 0;
		}

		n /= 10;
	}

	return 1;
}
