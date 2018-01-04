#include <stdio.h>
#include <math.h>

double funi(int, int);
double funr(int, int, int);

int main() {
	int n, p;

	scanf("%d%d", &n, &p);

	printf("%lf\n", funi(n, p));
	printf("%lf\n", funr(0, n, p));

	return 0;
}

double funi(int n, int p) {
	double sum;
	int i;

	for(i = n - 1; i >= 0; i--) {
		if(i == n - 1) {
			sum = sqrt(i / p + 1);
		}else {
			sum = sqrt(i / p + 1 + sum);	
		}
	}

	return sum;	
}

double funr(int i, int n, int p) {
	if(i == n - 1) {
		return sqrt(i / p + 1);
	}

	return sqrt(i / p + 1 + funr(i + 1, n, p));	
}
