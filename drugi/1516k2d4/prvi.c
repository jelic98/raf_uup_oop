#include <stdio.h>
#include <math.h>

double fi(int, int);
double fr(int, int, int);
int getP(int, int);

int main() {
	int n, p;

	scanf("%d%d", &n, &p);
	
	printf("%lf\n", fi(n, p));
	printf("%lf\n", fr(1, n, p));

	return 0;
}

double fi(int n, int p) {
	int i;
	double sum;

	for(i = n; i > 0; i--) {
		if(i == n) {
			sum = sqrt(getP(i, p));
		}else {
			sum = sqrt(getP(i, p) + sum);
		}	
	}

	return sum;
}

double fr(int i, int n, int p) {
	if(i == n) {
		return sqrt(getP(i, p));
	}

	return sqrt(getP(i, p) + fr(i + 1, n, p));
}

int getP(int i, int p) {
	int a, len = 0, oldP = p;

	while(p > 0) {
		len++;
		p /= 10;
	}

	p = oldP;
	
	i = len - i % len + 1;

	while(i-- > 0) {
		a = p % 10;
	
		p /= 10;
		
		if(p == 0) {
			p = oldP;	
		}
	}

	return a;
}
