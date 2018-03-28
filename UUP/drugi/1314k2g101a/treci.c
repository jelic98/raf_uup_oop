#include <stdio.h>

void modifikuj(char[]);

int main() {
	char *s;

	scanf("%s", s);

	modifikuj(s);

	printf("%s\n", s);

	return 0;
}

void modifikuj(char s[]) {
	int pos = 0, i, j, len = 0;

	while(*s) {
		pos += *s - '0';

		len++;

		s++;
	}

	s -= len;

	for(i = len - 1; i >= 0; i--) {
		for(j = 0; j < s[i] - '0'; j++) {
			s[--pos] = s[i];
		}
	}

	s[i] = '\0';
}
