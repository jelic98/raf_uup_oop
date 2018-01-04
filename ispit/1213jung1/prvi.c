#include <stdio.h>

double funi(int, int);
double funr(int, int, int);

int main() {
	int n, p;

	scanf("%d%d", &n, &p);

	printf("%lf\n", funi(n, p));
	printf("%lf\n", funr(1, n, p));

	return 0;
}

double funi(int n, int p) {
	double sum;
	int i;

	for(i = 0; i < n; i++) {
		p += i;
	}

	for(i = n; i > 0; i--) {
		if(i == n) {
			sum = p;
		}else {
			p -= i;
			sum = p + 1 / sum;	
		}
	}

	return sum;	
}

double funr(int i, int n, int p) {
	if(i == n) {
		return p;
	}

	return p + 1 / funr(i + 1, n, p + i);	
}
