#include <stdio.h>

#define SIZE 100

int main() {
	char s[SIZE];

	gets(s);

	int i = 0, res[SIZE] = {0};

	while(s[i]) {
		char c = s[i];

		if(c >= 97) {
			c -= 32;
		}

		if(c < 'A' || c > 'Z') {
			i++;
			continue;
		}

		int found = 0, j = 0;

		while(j < i) {
			if(s[j] == s[i]) {
				found = 1;
				break;	
			}

			j++;	
		}

		if(!found) {
			printf("%c", s[i]);
		}

		i++;
	}

	printf("\n");
		
	return 0;
}
