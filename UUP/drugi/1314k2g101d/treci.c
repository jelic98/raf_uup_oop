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
	int i, len = -1;

	while(len++, *s++);

	s -= len + 1;

	for(i = 0; i < len - 1; i++) {
		s[i] = (s[i] + s[i + 1]) / 2 + (s[i] + s[i + 1]) % 2;
	}

	s[i] = '\0';
}
