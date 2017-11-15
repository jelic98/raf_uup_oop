#include <stdio.h>

int fun(int);

int main() {
	char c;
	int a, res = 0;

	do {
		scanf("%d", &a);
		
		res += fun(a);
	}while(a != 0);
	
	printf("%d\n", res);

	return 0;
}

int fun(int n) {	
	while(n / 10 != 0) {
		n /= 10;
	}

	return n;	
}
