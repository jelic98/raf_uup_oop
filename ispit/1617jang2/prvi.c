#include <stdio.h>
#include <math.h>

double funi(int);
double funr(int, int, int);

int main() {
	int n;

	//scanf("%d", &n);
	n = 6;

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
		printf("%d / %d\n", p, 2 * n - i + 1);

		if(i == n) {
			sum = sqrt(p);
		}else {
			sum = sqrt((float) p / (2 * n - i + 1) + sum);
		}
		
		p -= i - 1;
	}

	return sum;
}

double funr(int i, int n, int p) {
	if(i == n - 1) {
		return sqrt(i + p); 	
	}

	return sqrt((float) (i + p) / (2 * n - i) + funr(i + 1, n, i + p));	
}
