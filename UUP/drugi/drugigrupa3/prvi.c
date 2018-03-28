#include<stdio.h>
#include<math.h>

double fi(int);
double fr(int, int, int);

int main() {
	int n;

	scanf("%d", &n);

	printf("%lf\n", fi(n));
	printf("%lf\n", fr(1, n, 0));

	return 0;
}

double fi(int n) {
	double sum = 0;
	int i, p = 0;

	for(i = n; i > 0; i--) {
		if(++p > n / 2) {
			p = 1;
		}
	
		sum	= sqrt(i * p + sum);
	}

	return sum;
}

double fr(int i, int n, int p) {
	if(i == 1) {
		if(n % 2) {
			p = n / 2;
		}else {
		 	p = 0;		
		}
	}

	if(--p <= 0) {
		p = n / 2;
	}


	if(i == n) {
		return sqrt(i * p);
	}

	return sqrt(i * p + fr(i + 1, n, p));	
}
