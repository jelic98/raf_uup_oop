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
	int i;
	double sum;

	for(i = n; i > 0; i--) {
		if(i == n) {
			sum = sqrt(2 * i - 1);
		}else {
			sum = sqrt((2 * i - 1) * (n - i + 1) + sum);
		}
	}

	return sum;
}

double fr(int i, int n) {
	if(i == n) {
		return sqrt(2 * i - 1);	
	}

	return sqrt((2 * i - 1) * (n - i + 1) + fr(i + 1, n));	
}
