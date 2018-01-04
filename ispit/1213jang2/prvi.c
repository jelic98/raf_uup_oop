#include <stdio.h>
#include <math.h>

double funi(int, int);
double funr(int, int, int);

int main() {
	int n, k;

	scanf("%d%d", &n, &k);

	printf("%lf\n", funi(n, k));
	printf("%lf\n", funr(1, n, k));

	return 0;
}

double funi(int n, int k) {
	double sum;
	int i;

	for(i = n; i > 0; i--) {
		int p = i / 2 + i % 2;

		if(!(i % 2)) {
			p += k;
		}

		if(i == n) {
			sum = sqrt(p);
		}else {
			sum = sqrt(p + sum);	
		}
	}

	return sum;	
}

double funr(int i, int n, int k) {
	int p = i / 2 + i % 2;

	if(!(i % 2)) {
		p += k;
	}

	if(i == n) {
		return sqrt(p);
	}
	
	return sqrt(p + funr(i + 1, n, k));	
}
