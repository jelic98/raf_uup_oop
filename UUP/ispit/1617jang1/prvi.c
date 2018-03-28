#include <stdio.h>

double funi(int);
double funr(int, int, int);

int main() {
	int n;

	scanf("%d", &n);

	printf("%lf\n", funi(n));
	printf("%lf\n", funr(0, n, 1));

	return 0;
}

double funi(int n) {
	int i, p = 1;
	double sum;

	for(i = 0; i < n; i++) {
		p += i;
	} 

	for(i = n; i > 0; i--) {
		if(i == n) {
			sum = p;	
		}else {
			p -= i;
			sum = p + (2 * n - i + 1) / sum;
		}
	}

	return sum;
}

double funr(int i, int n, int p) {
	if(i == n - 1) {
		return i + p; 	
	}

	return i + p + (2 * n - i) / funr(i + 1, n, i + p);	
}
