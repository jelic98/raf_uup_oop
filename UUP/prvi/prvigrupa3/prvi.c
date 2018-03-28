#include <stdio.h>

int pom(int, int);

int main() {
	int a, b, c, res, k = 5;

	scanf("%d%d%d", &a, &b, &c);

	res = pom(a, k) + pom(b, k) + pom(c, k);

	printf("%d\n", res);

	return 0;
}

int pom(int arg, int k) {
	int m = 0, fact = 1;
	
	while(arg > 0) {
		if(arg % 10 >= k) {
			m += fact * (arg % 10);
			fact *= 10;
		}
		
		arg /= 10;
	}

	return m;
}
