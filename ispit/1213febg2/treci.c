#include <stdio.h>

#define SIZE 100

int main() {
	char s[SIZE];

	scanf("%s", s);

	int res[SIZE];

	int i = -1, count = -1;
	int n = 0, max = 0;

	char tmp[SIZE];

	while(1) {
		i++;

		if(s[i] == '-' || s[i] == '\n' || s[i] == EOF) {
			res[++count] = n;

			if(n > max) {
				max = n;	
			}

			n = 0;
		}else if(s[i] >= '0' && s[i] <= '9') {
			n *= 10;
			n += s[i] - '0';
		}

		if(s[i] == EOF || s[i] == '\n') {
			break;
		}
	}	

	for(i = 0; i <= count; i++) {
		if(res[i] == max) {
			printf("%d\n", res[i]);	
		}
	}

	return 0;
}
