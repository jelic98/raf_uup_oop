#include <stdio.h>
#include <math.h>

double funi(int);
double funr(int, int, int);

int main() {
	int n;

	scanf("%d", &n);

	printf("%lf\n", funi(n));
	printf("%lf\n", funr(1, n, 1));

	return 0;
}

double funi(int n) {
	double sum;
	int i, p = 1;

	for(i = 0; i < n; i++) {
		p += i;	
	}

	for(i = n; i > 0; i--) {
		if(i == n) {
			sum = sqrt(p);
		}else {
			p -=  i;
			sum = sqrt(p + sum);	
		}
	}

	return sum;	
}

double funr(int i, int n, int p) {
	if(i == n) {
		return sqrt(p);
	}
	
	return sqrt(p + funr(i + 1, n, p + i));	
}
