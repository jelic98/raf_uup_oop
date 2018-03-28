#include <stdio.h>

#define SIZE 100

char* napravi(char*);

char cifre[16][4] = {
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
	char *s;

	scanf("%s", s);

	printf("%s\n", napravi(s));

	return 0;
}

char* napravi(char *s) {
	int j;
	char arr[SIZE];
	char *t;

	t = arr;

	while(*s) {
		if(*s >= 'A' && *s <= 'F') {
			for(j = 0; j < 4; j++, t++) {
				*t = cifre[*s - 'A' + 10][j];
			}
		}else {
			for(j = 0; j < 4; j++, t++) {
				*t = cifre[*s - '0'][j];
			}
		}

		s++;	
	}
		
	*t = '\0';
	
	t = arr;

	return t;
}
