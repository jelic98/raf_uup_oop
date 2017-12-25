#include <stdio.h>

void modifikuj(char[]);

int main() {
	char *s;

	gets(s);

	modifikuj(s);

	printf("%s\n", s);

	return 0;
}

void modifikuj(char s[]) {
	int i, j, k, len = -1;
	char p;

	while(len++, *s++);

	s -= len + 1;

	for(i = 0; i < len; i++) {
		for(j = 0; j < i; j++) {
			if(s[i] == s[j] && s[i] != ' ' && s[i] != '\0') {
				for(k = i; k < len; k++) {
					s[k] = s[k + 1];	
				}

				s[k] = '\0';

				i--;

				break;
			}
		}
	}
}
