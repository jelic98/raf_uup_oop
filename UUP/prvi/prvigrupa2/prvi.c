#include <stdio.h>

int pom(int);
int abs(int);
int min(int, int);

int main() {
	int min, max;

	scanf("%d%d", &min, &max);

	while(min++ <= max) {
		if(pom(min - 1) > 5) {
			printf("%d\n", min - 1);
		}	
	}

	return 0;
}

int pom(int arg) {
	int res, prev = -1;

	prev = arg % 10;
	arg /= 10;

	res = abs(prev - arg % 10);
	arg /= 10;

	while(arg > 0) {
		res = min(res, abs(arg % 10 - prev));
	
		prev = arg % 10;

		arg /= 10;
	}

	return res;
}

int abs(int a) {
	if(a < 0) {
		a *= -1;
	}

	return a;	
}

int min(int a, int b) {
	if(a < b) {
		return a;
	}

	return b;
}
