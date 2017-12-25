#include <stdio.h>

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
	double sum = 0.0;
	
	for(i = n; i > 0; i--) {
		if(i == n) {
			sum += (i / 2 + i % 2);
		}else {
			sum = 1 / sum + (i / 2 + i % 2);
		}
	}

	return sum;
}

double fr(int i, int n) {
	if(i == n) {
		return (i / 2 + i % 2);
	}

	return (i / 2 + i % 2) + 1 / fr(i + 1, n);
}
