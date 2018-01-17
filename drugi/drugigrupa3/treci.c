#include <stdio.h>

#define SIZE 100

int main() {
	char tmp, *p, s[SIZE];
	int pos = 0, i = 0;

	scanf("%s", s);

	p = s;
	tmp = s[0];

	while(1) {
		if(s[i] >= '0' && s[i] <= '9') {
			if(s[i + 1] >= '0' && s[i + 1] <= '9') {
				char p = tmp;
				tmp = s[i + 1];
				s[i + 1] = p;
			}
		}else {
			s[pos] = tmp;
			tmp = s[i + 1];
			
			pos = i + 1;

			if(s[i] == '\0' || s[i] == '\n') {
				break;	
			}
		}

		i++;
	}

	printf("%s\n", p);

	return 0;
}
