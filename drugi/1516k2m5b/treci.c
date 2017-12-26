#include <stdio.h>

void modifikuj(char*);
char* trim(char*);

int main() {
	char s[100];

	gets(s);

	modifikuj(s);

	printf("%s\n", trim(s));

	return 0;
}

void modifikuj(char *s) {
	int count = 0, len = -1, i, j;
	char *p, c;

	while(len++, *s++);

	s -= len;

	p = s - 1;

	while(1) {
		c = (*s >= 97) ? *s - 32 : *s;

		if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
			count++;
		}else if(c == ' ' || c == 0) {
			if(count % 2) {
				i = s - p + 1;

				while(--i > 0) {
					for(j = 0; j < len; j++) {
						p[j] = p[j + 1];	
					}
				}

				s = p;
			}

			p = s;

			count = 0;	
		}
		
		if(*s == 0) {
			break;
		}
		
		s++;
	}
}

char* trim(char *s) {
	if(*s == ' ') {
		s++;
	}

	return s;
}
