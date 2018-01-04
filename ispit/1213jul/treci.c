#include <stdio.h>

#define SIZE 100

int main() {
	char s[SIZE];
	char p[SIZE];

	gets(s);
	gets(p);

	int i = 0, res[SIZE] = {0};

	while(s[i]) {
		if(s[i] >= 97) {
			s[i] -= 32;	
		}

		if(s[i] < 'A' || s[i] > 'Z') {
			i++;
			continue;
		}

		char *pp = p;

		int found = 0;

		while(*pp) {
			if(*pp >= 97) {
				*pp -= 32;	
			}

			if(*pp == s[i]) {
				found = 1;
				break;	
			}

			pp++;	
		}

		if(!found) {
			printf("ne moze\n");
			return 0;	
		}

		i++;
	}
		
	printf("moze\n");

	return 0;
}
