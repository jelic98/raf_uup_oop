#include <stdio.h>

#define SIZE 100

void modifikuj(char[]);

int main() {
	char s[SIZE];

	gets(s);

	modifikuj(s);

	printf("%s\n", s);

	return 0;
}

void modifikuj(char s[]) {
    int pos = 0, i = 0;
    char t[SIZE], *pt, *ps;

    ps = s;

	while(1) {
        if(*s == ' ' || *s == '\0' || *s == '\n' || *s == '\t') {
            t[pos] = '\0';

            if(t[0] < 'a' || t[pos - 1] < 'a') {
                pt = t;

                while(*pt) {
                    ps[i++] = *pt;
                    pt++;
                }

                if(*s == '\0') {
                    ps[i] = '\0';
                    break;
                }else {
                    ps[i++] = ' ';
                }
            }

            pos = 0;
        }else {
            t[pos++] = *s;
        }

        s++;
	}
}

