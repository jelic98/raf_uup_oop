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

	for(j = 0; j < n; j++) {
		a[n - 1][j] = a[0][j];
	}

    int p;

    for(j = 0; j < n / 2 + n % 2; j++) {
        p = a[n - 1][j];
        a[n - 1][j] = a[n - 1][n - j - 1];
        a[n - 1][n - j - 1] = p;
    }

    for(i = n - 2; i >= 0; i--) {
        for(j = 0; j < n; j++) {
            if(i % 2) {
                diff = 1;
            }else {
                diff = 2;
            }

            a[i][j] = (a[i + 1][j] + diff) % 10;
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

