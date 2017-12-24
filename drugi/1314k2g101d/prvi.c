#include <stdio.h>
#include <math.h>

double fi(int);
double fr(int, int);

int main() {
	int n;

	scanf("%d", &n);

	printf("%lf\n", fi(n));
	printf("%lf\n", fr(1, n));

	return 0;
}

double fi(int n) {
	int i, a;
	double sum;

	for(i = n; i > 0; i--) {
		if(i % 2) {
			a = 1;	
		}else {
			a = n;
		}
	
		if(i == n) {
			sum = sqrt(a);
		}else {
			sum = sqrt(a + sum);
		}
	}

	return sum;
}

double fr(int i, int n) {
	int a;
	
	if(i % 2) {
		a = 1;	
	}else {
		a = n;
	}

	if(i == n) {
		return sqrt(a);	
	}

	return sqrt(a + fr(i + 1, n));
}
