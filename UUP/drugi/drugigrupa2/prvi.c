#include <stdio.h>
#include <math.h>

double fi(int n) {
    double sum;
    int i;

    for(i = n; i > 0; i--) {
		if(i == n) {
			sum = n - i + 1; 
			continue;
		}

        if(i % 2) {
            sum = (n - i + 1) + sqrt(1.0) / sum;
        }else {
            sum = (n - i + 1) + sqrt(2.0) / sum;
        }
    }

    return sum;
}

double fr(int i, int n) {
    if(i == n) {
        return n - i + 1;
    }

    if(i % 2) {
        return (n - i + 1) + sqrt(1.0) / fr(i + 1, n);
    }else {
        return (n - i + 1) + sqrt(2.0) / fr(i + 1, n);
    }
}

int main() {
    int n;

    scanf("%d", &n);

    printf("%lf\n", fi(n));
    printf("%lf\n", fr(1, n));

    return 0;
}
