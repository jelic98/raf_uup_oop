#include <stdio.h>

double fi(int, int);
double fr(int, int, int);

int main() {
	int n, p;

	//scanf("%d%d", &n, &p);
	n = 6;
	p = 5;

	printf("%lf\n", fi(n, p));
	printf("%lf\n", fr(1, n, p));

	return 0;
}

double fi(int n, int p) {
	int i;
	double sum;

	for(i = 0, p -= 4; i < n; i++, p += (i % 2) ? 2 : 4);

	for(i = 0; i < n; i++, p -= (i % 2) ? 2 : 4) {
		if(i == n) {
			sum = p;	
		}	
	
		sum = p + 1 / sum;
	}

	return sum;
}

double fr(int i, int n, int p) {
	if(i == n) {
		return p;	
	}
	
	return p + 1 / fr(i + 1, n, p += (i % 2) ? 2 : 4);	
}
