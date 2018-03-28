#include <stdio.h>

int pom(int, int);

int main() {
	int i, x, sum = 0, n = 3, k = 6;

	for(i = 0; i < n; i++) {
		scanf("%d", &x);

		sum += pom(x, k);
	}

	printf("%d\n", sum);

	return 0;
}

int pom(int arg, int k) {
	int n = 0, fact = 1;

	while(arg > 0) {
		if(arg % 10 <= k) {
			n += fact * (arg % 10);
			fact *= 10;
		}

		arg /= 10;
	}

	return n;
}
