#include <stdio.h>

#define SIZE 100

char* modifikuj(char*);

int main() {
	char s[SIZE];

    printf("Unesite string: ");
	gets(s);

	printf("%s\n", modifikuj(s));

	return 0;
}

char* modifikuj(char* s) {
	int i, n;

	while(*s) {
		if(*s == *(s + 1)) {
			n++;
		}
	}

	printf("%d", n);

	return s;
}
