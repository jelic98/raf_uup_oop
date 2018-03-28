#include <stdio.h>

#define SIZE 100

void modifikuj(char[], int);

int main() {
	char s[SIZE];
	int n;

	gets(s);

	scanf("%d", &n);

	modifikuj(s, n);

	printf("%s\n", s);

	return 0;
}

void modifikuj(char s[], int n) {
    int pos = 0, i = 0, found = 0;
    char t[SIZE], *pt, *ps;

    ps = s;

	while(1) {
        if(*s == ' ' || *s == '\0' || *s == '\n' || *s == '\t') {
            t[pos] = '\0';

            if(pos >= n) {
                pt = t;
				
				if(found) {
					ps[i++] = ' ';
				}

				found = 1;
	
                while(*pt) {
                    ps[i++] = *pt;
                    pt++;
                }
			}

			if(*s == '\0') {
                ps[i] = '\0';
                break;
            }

            pos = 0;
        }else {
            t[pos++] = *s;
        }

        s++;
	}
}

