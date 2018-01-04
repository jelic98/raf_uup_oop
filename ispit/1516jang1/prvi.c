#include <stdio.h>

double funi(int);
double funr(int, int);
int fib(int);

int main() {
	int n;

	scanf("%d", &n);

	printf("%lf\n", funi(n));
	printf("%lf\n", funr(1, n));

	return 0;	
}

double funi(int n) {
	double sum;
	int i;

	for(i = n; i > 0; i--) {
		if(i == n) {
			sum = fib(i);
		}else {
			sum = fib(i) + fib(n - i) / sum;
		}
	}

	return sum;	
}

double funr(int i, int n) {
	if(i == n) {
		return fib(i);	
	}

	return fib(i) + fib(n - i) / funr(i + 1, n);	
}

int fib(int n) {
	if(n <= 2) {
		return 1;
	}

	return fib(n - 1) + fib(n - 2);
}
