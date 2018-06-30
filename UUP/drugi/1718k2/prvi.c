#include <stdio.h>

double fi(int n) {
    int i, up, down;
    double sum;

    up = 1;
    down = n;

    for(i = 0; i < n; i++) {
        if(i % 2) {
            down--;
        }else {
            up++;
        }
    }

    up -= n % 2;
    down -= n % 2;

    for(i = n; i > 0; i--) {
        if(i == n) {
            if(i % 2 == 0) {
                sum = down--;
            }else {
                sum = up++;
            }
        }else {
            if(i % 2 == 0) {
                sum = down-- + (2 * n - 2 * i + 2) / sum;
            }else {
                sum = up++ + (2 * n - 2 * i + 2) / sum;

            }
        }
    }

    return sum;
}

double fr(int i, int n, int up, int down) {
    if(i == n) {
        if(i % 2) {
            return down;
        }else {
            return up;
        }
    }

    if(i % 2) {
        return up + (2 * n - 2 * i + 2) / fr(i + 1, n, up - 1, down);
    }else {
        return down + (2 * n - 2 * i + 2) / fr(i + 1, n, up, down + 1);
    }
}

int main() {
    int n;

    scanf("%d", &n);

    if(n == 0) {
        printf("%d\n", 0);
    }else {
        printf("%lf\n", fi(n));
        printf("%lf\n", fr(1, n, n, 1));
    }

    return 0;
}
