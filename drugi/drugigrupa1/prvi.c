#include <stdio.h>
#include <math.h>

double fi(int n) {
    double sum = 0;
    int i;

    for(i = n; i > 0; i--) {
        if(i % 2) {
            sum = sqrt(1.0 / (n - i + 1) + sum);
        }else {
            sum = sqrt(2.0 / (n - i + 1) + sum);
        }
    }

    return sum;
}

double fr(int i, int n) {
    if(i == n) {
        if(i % 2) {
            return sqrt(1.0 / (n - i + 1));
        }else {
            return sqrt(2.0 / (n - i + 1));
        }
    }

    if(i % 2) {
        return sqrt(1.0 / (n - i + 1) + fr(i + 1, n));
    }else {
        return sqrt(2.0 / (n - i + 1) + fr(i + 1, n));
    }
}

int main() {
    int n;

    scanf("%d", &n);

    printf("%lf\n", fi(n));
    printf("%lf\n", fr(1, n));

    return 0;
}
