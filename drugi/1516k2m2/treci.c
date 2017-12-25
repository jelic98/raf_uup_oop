#include <stdio.h>

void modifikuj(char[]);

int main() {
	char *s;
	
//	scanf("%s", s);
char s1[100] = "977742221";
s = s1;

	modifikuj(s);

	printf("%s\n", s);

	return 0;
}

void modifikuj(char s[]) {
	int maxlen, pos = 0, i, j, len = 0;
	char prev = *s;

	while(*s) {
		if(prev - *s != 0) {
			pos += prev - *s - 1;
		}

		len++;

		prev = *s;

		s++;
	}

	pos += len;
	
	maxlen = pos;

	s -= len;

	for(i = len - 1; i > 0; i--) {
		if (s[i] < s[i - 1]){
			for(j = s[i]; j < s[i - 1]; j++) {
				s[--pos] = j;
			}
		}else {
			s[--pos] = j;
		}
	}

	s[maxlen] = '\0';
}
