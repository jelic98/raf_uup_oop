#include <stdio.h>

int main() {
    int a[100][100];
    int i, j, n, diff;

    scanf("%d", &n);

    j = 0;

    while(n > 0) {
        a[0][j++] = n % 10;
        n /= 10;
    }

    n = j;

    int p;

    for(j = 0; j < n / 2 + n % 2; j++) {
        p = a[0][j];
        a[0][j] = a[0][n - j - 1];
        a[0][n - j - 1] = p;
    }

    for(i = 1; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i % 2) {
                diff = 1;
            }else {
                diff = 2;
            }

            a[i][j] = a[i - 1][j] - diff;

            if(a[i][j] < 0) {
                a[i][j] += 10;
            }
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%3d", a[i][j]);
        }

        printf("\n");
    }

    return 0;
}

