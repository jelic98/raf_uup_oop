#include<stdio.h>

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
	double sum;
	int i;

	for(i = n; i > 0; i--) {
		if(i == n) {
			sum = i;
			continue;	
		}

		if(i % 2) {
			sum	= i + (2 * n - 2 * (i - 1)) / sum;
		}else {
			sum	= i - (2 * n - 2 * (i - 1)) / sum;
		}
	}

	return sum;
}

double fr(int i, int n) {
	if(i == n) {
		return i;
	}

	if(i % 2) {
		return i + (2 * n - 2 * (i - 1)) / fr(i + 1, n);
	}else {	
		return i - (2 * n - 2 * (i - 1)) / fr(i + 1, n);
	}
}
