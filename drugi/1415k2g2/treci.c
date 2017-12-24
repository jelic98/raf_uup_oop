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
	char prev = 0;
	int i, pos, len = 0, newLen = 0;

	while(*s) {
		len++;
		
		if(*s == prev) {
			newLen++;
		}

		prev = *s;

		s++;
	}

	s -= len;

	newLen += len;

	prev = 0;
	pos = newLen - 1;

	for(i = len - 1; i >= 0; i--) {
		if(s[i] == prev) {
			s[pos--] = '#';
		}
		
		s[pos--] = s[i];

		prev = s[i];
	}
}
