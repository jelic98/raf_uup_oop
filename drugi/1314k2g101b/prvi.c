#include <stdio.h>
#include <math.h>

double fi(int);
double fr(int, int, int);

int main() {
	int n;

	scanf("%d", &n);

	printf("%lf\n", fi(n));
	printf("%lf\n", fr(1, n, 1));

	return 0;
}

double fi(int n) {
	int i, p = 0;
	double sum;

	for(i = 1; i <= n; p += i++);		

	for(i = n; i > 0; i--) {
		if(i == n) {
			sum = sqrt(p);
		}else {	
			if(i % 2) {
				sum = sqrt(p + sum);
			}else {
				sum = sqrt(p - sum);
			}
		}
		
		p -= i;
	}

	return sum;
}

double fr(int i, int n, int p) {
	if(i == n) {	
		return sqrt(p);
	}else {
		i++;

		if(i % 2) {
			return sqrt(p - fr(i, n, p + i));
		}else {
			return sqrt(p + fr(i, n, p + i));
		}	
	}
}
