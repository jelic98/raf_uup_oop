#include <stdio.h>

#define SIZE 100

int main() {
	char s[SIZE];

	scanf("%s", s);

	char res[SIZE][SIZE];

	int i = -1, count = -1;
	int len = 0, maxLen = 0;

	char tmp[SIZE];

	while(1) {
		i++;

		if(s[i] == '-' || s[i] == '\n' || s[i] == EOF) {
			if(len > 0) {
				tmp[len] = '\0';	
			}

			count++;

			int j = 0;

			while(tmp[j]) {
				res[count][j] = tmp[j];
				j++;
			}

			res[count][j] = '\0';

			if(len > maxLen) {
				maxLen = len;	
			}

			len = 0;
		}else if(s[i] >= 'A' && s[i] <= 'Z') {
			tmp[len++] = s[i];
		}

		if(s[i] == EOF || s[i] == '\n') {
			break;
		}
	}	

	for(i = 0; i <= count; i++) {
		char *p = res[i];
		
		len = -1;

		while(len++, *p++);

		if(len == maxLen) {
			printf("%s\n", res[i]);	
		}
	}

	return 0;
}
