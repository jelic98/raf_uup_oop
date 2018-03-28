#include <stdio.h>

int ista(char c1, char c2) {
	if(c1 >= 97) {
		c1 -= 32;	
	}
	
	if(c2 >= 97) {
		c2 -= 32;	
	}
	
	return c1 == c2;
}

int main() {
	char s[100];

	scanf("%s", s);

	int i = 0, j, len = 0;

	while(s[i]) {
		i++;
		len++;	
	}

	char min[100], max[100];
	int minLen = len, maxLen = 0;

	for(i = 0; i < len; i++) {
		for(j = i + 1; j < len; j++) {
			if(ista(s[i], s[j])) {
				if(j - i > maxLen) {
					maxLen = j - i;

					int p = i;

					while(p <= j) {
						max[p - i] = s[p];
						p++;
					}

					max[p - i] = '\0'; 
				}else if(j - i < minLen) {
					minLen = j - i;	
	
					int p = i;

					while(p <= j) {
						min[p - i] = s[p];
						p++;
					}

					min[p - i] = '\0'; 
				}
			}
		}
	}

	printf("najkraci: %s\n", min);
	printf("najduzi: %s\n", max);

	return 0;
}
