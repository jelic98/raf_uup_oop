#include <stdio.h>

void sort(char[], int);

int main() {
	int i, max = 0, len;
	char *s, s1[100];

	gets(s1);
	s = s1;

	while(*s) {
		len = 0;
		
		while(1) {
			if(*s < 'A' || *s > 'Z') {
				break;
			}

			len++;
			s++;
		}
			
		s -= len;

		sort(s, len);

		s += len + 1;
		max += len + 1;
	}

	s -= max;

	printf("%s\n", s);

	return 0;
}

void sort(char s[], int n) {
	int i, j;
	char p;

	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			if(s[i] > s[j]) {
				p = s[i];
				s[i] = s[j];
				s[j] = p;
			}
		}
	}
}
