#include <stdio.h>

int main() {
	int i, max = 0, len;
	char s1[100], p;
	char *s;

	scanf("%s", s1);
	s = s1;

	while(*s) {
		len = 0;
		
		while(1) {
			if(*s < '0' || *s > '9') {
				break;
			}

			len++;
			s++;
		}
			
		s -= len;

		for(i = 0; i < len / 2; i++) {
			p = s[i];
			s[i] = s[len - i - 1];
			s[len - i - 1] = p;
		}
		
		s += len + 1;
		max += len + 1;
	}

	s -= max;

	printf("%s\n", s);

	return 0;
}
