#include <stdio.h>

double fi(int, int);
double fr(int, int, int);
int get_p(int, int);

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
			sum = 1;
		}else {
			sum = 1 + get_p(i, n) / sum;
		}
	}

	return sum;
}

double fr(int i, int n, int p) {
	p = get_p(i, n);
	
	if(i == n) {
		return 1;	
	}

	return 1 + p / fr(i + 1, n, p);
}

int get_p(int i, int n) {
	i = n - i + 1;

	int diff = (i % 2) ? 1 : -1;

	return (2 * (i + (n - i) / 2) + diff) - 2;
}
