#include <stdio.h>

int pom(int);

int main() {
	int res, i, min, max;

	scanf("%d%d", &min, &max);

	res = 0;

	for(i = min; i < max; i++) {
		printf("%d %d\n", i, pom(i));
	
		res += pom(i) * i;	
	}

	printf("%d\n", res);

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
