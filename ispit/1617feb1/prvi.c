#include <stdio.h>
#include <math.h>

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
			sum = fib(i) + pow(i % 2 + 1, n - i + 1) / sum;	
		}
	}

	return sum;
}

double funr(int i, int n) {
	if(i == n) {
		return fib(i);	
	}

	return fib(i) + pow(i % 2 + 1, n - i + 1) / funr(i + 1, n);	
}

int fib(int n) {
	if(n <= 0) {
		return 0;
	}
	
	int f1, f2, i, p;

	f1 = 1;
	f2 = 1;

	for(i = 2; i < n; i++) {
		p = f1;
		f1 += f2;
		f2 = p;
	}

	return f1;
}
