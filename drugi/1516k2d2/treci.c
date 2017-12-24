#include <stdio.h>

#define SIZE 100

char* napravi(char*);
void dodaj(char*, char*);

char cifre[][SIZE] = {
	"0000",	
	"0001",	
	"0010",	
	"0011",	
	"0100",	
	"0101",	
	"0110",	
	"0111",	
	"1000",	
	"1001",	
	"1010",	
	"1011",	
	"1100",	
	"1101",	
	"1110",	
	"1111"	
};

int main() {
	char s[SIZE];

	scanf("%s", s);

	printf("%s\n", napravi(s));

	return 0;
}

char* napravi(char *s) {
	int pos, i = 0;
	char t[SIZE];

	while(*s) {
		if(*s >= 'A' || *s <= 'F') {
			dodaj(t, cifre[*s - 'A' + 10]);
		}else {
			dodaj(t, cifre[*s - '0']);
		}

		i += 4;

		s++;	
	}

	t[i] = '\0';

	return t;
}

void dodaj(char *dest, char *src) {	
	while(*dest++);

	while((*dest++ = *src++));
}
