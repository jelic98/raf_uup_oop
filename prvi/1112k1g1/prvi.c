#include <stdio.h>

int hasEven(int);

int main() {
	int i, res, min, max;

	scanf("%d%d", &min, &max);

	res = 0;

	for(i = min; i < max; i++) {
		res += hasEven(i) * i;
	}

	printf("%d\n", res);

	return 0;	
}

int hasEven(int n) {
	while(n / 10 > 0) {	
		n /= 10;
	}
	
	if(n % 2 == 0) {
		printf("%d\n", n);
		return 1;
	}

	return 0;	
}
