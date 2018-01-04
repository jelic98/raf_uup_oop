#include <stdio.h>
#include <math.h>

double funi(int);
double funr(int, int, int);

int main() {
	int n, p;

	scanf("%d", &n);

	printf("%lf\n", funi(n));
	printf("%lf\n", funr(0, n, n));

	return 0;
}

double funi(int n) {
	double sum;
	int i, p = n;

	for(i = 0; i < n; i++) {
		if(i % 2) {
			p -= i;
		}else {
			p += i;
		}	
	}

	for(i = n - 1; i >= 0; i--) {
		
		if(i == n - 1) {
			sum = sqrt(p);
		}else {
			if(i % 2) {
				p -= i;
			}else {
				p += i;
			}

			sum = sqrt(p + sum);	
		}
	}

	return sum;	
}

double funr(int i, int n, int p) {
	if(i == n - 1) {
		return sqrt(p);
	}

	return sqrt(p + funr(i + 1, n, (i % 2) ? p + i : p - i));	
}
