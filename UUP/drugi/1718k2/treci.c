#include <stdio.h>
#include <string.h>

#define SIZE 100

int main() {
    char *arr[SIZE], *parr, num[SIZE] = {0}, s[SIZE], *ps, t[SIZE], *pt;
    int n = 0, i, j, found;

    gets(s);

    char parser[2] = " ";

    ps = strtok(s, parser);

    while(ps) {
        found = 0;

        for(i = n - 1; i >= 0; i--) {
            if(!strcmp(ps, arr[i])) {
                num[n] = num[i] + 1;
                break;
            }
        }

        arr[n] = ps;

        n++;

        ps = strtok(NULL, parser);
    }

    pt = t;

    found = 0;

    for(i = 0; i < n; i++) {
        if(num[i]) {
            break;
        }

        for(j = 0; j < n; j++) {
            if(num[j] == 1 && !strcmp(arr[i], arr[j])) {
                parr = arr[i];

                if(found) {
                    *pt = ' ';
                    pt++;
                }

                while(*parr) {
                    *pt = *parr;
                    pt++;
                    parr++;
                }

                found = 1;
                break;
            }
        }
    }

    *pt = '\0';

    printf("%s\n", t);

    return 0;
}
