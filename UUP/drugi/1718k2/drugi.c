#include <stdio.h>

#define SIZE 100

void napravi(int n) {
    int a[SIZE][SIZE], i, j, p, count, len, b[SIZE];

    i = 0;

    while(n > 0) {
        b[i++] = n % 10;
        n /= 10;
    }

    len = i;

    for(i = 0; i < len / 2; i++) {
        p = b[i];
        b[i] = b[len - i - 1];
        b[len - i - 1] = p;
    }

    if(len % 2) {
        for(i = 0; i < len; i++) {
            a[len / 2][i] = b[i];
            a[len / 2 + 1][i] = b[i];
        }

        p = 0;
        count = 0;

        for(i = len / 2 - 1; i >= 0; i--) {
            if(count++ % 2 == 0) {
                p++;
            }

            for(j = 0; j < len; j++) {
                a[i][j] = (a[len / 2][j] + p) % 10;
            }
        }

        p = 0;
        count = 0;

        for(i = len / 2 + 2; i < len; i++) {
            if(count++ % 2 == 0) {
                p++;
            }

            for(j = 0; j < len; j++) {
                a[i][j] = a[len / 2][j] - p;

                if(a[i][j] < 0) {
                    a[i][j] += 10;
                }
            }
        }
    }else {
        for(i = 0; i < len; i++) {
            a[len / 2][i] = b[i];
            a[len / 2 - 1][i] = b[i];
        }

        p = 0;
        count = 0;

        for(i = len / 2 - 2; i >= 0; i--) {
            if(count++ % 2 == 0) {
                p++;
            }

            for(j = 0; j < len; j++) {
                a[i][j] = (a[len / 2][j] + p) % 10;
            }
        }

        p = 0;
        count = 0;

        for(i = len / 2 + 1; i < len; i++) {
            if(count++ % 2 == 0) {
                p++;
            }

            for(j = 0; j < len; j++) {
                a[i][j] = a[len / 2][j] - p;

                if(a[i][j] < 0) {
                    a[i][j] += 10;
                }
            }
        }
    }

    for(i = 0; i < len; i++) {
        for(j = 0; j < len; j++) {
            printf("%2d ", a[i][j]);
        }

        printf("\n");
    }
}

int main() {
    int n;

    scanf("%d", &n);

    napravi(n);

    return 0;
}
