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
	int i, j;
	char arr[SIZE];
	char *t, *p;

	t = arr;

	while(*s) {
		for(i = 0; i < 16; i++) {
			p = s;
			
			for(j = 0; j < 4; j++, p++) {
				if(*p != cifre[i][j]) {
					break; 					
				} 		

				if(j == 3) {
					if(i > 9) {
						*t = 'A' + i - 10;
					}else {
						*t = '0' + i;
					}

					t++;
				}
			}
		}

		s += 4;
	}
		
	*t = '\0';
	
	t = arr;

	return t;
}
