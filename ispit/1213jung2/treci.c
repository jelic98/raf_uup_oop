#include <stdio.h>

#define SIZE 100

int abs(int);

int main() {
	char s[SIZE];
	int p;

	gets(s);
	scanf("%d", &p);

	int res[SIZE], count = -1, n, i = 0, j, k;

	while(1) {
		if(s[i] >= '0' && s[i] <= '9') {
			n *= 10;
			n += s[i] - '0';
		}else if(s[i] == ' ' || s[i] == '\n' || s[i] == EOF) {
			res[++count] = n;
		
			n = 0;
		}

		if(s[i] == '\n' || s[i] == EOF) {
			break;
		}

		i++;
	}

	int min = p, minI, minJ, minK;

	for(i = 0; i <= count; i++) {
		for(j = 0; j <= count; j++) {
			for(k = 0; k <= count; k++) {
				if(i != j && i != k && j != k && abs((res[i] + res[j] + res[k]) / 3 - p) < min) {
					minI = res[i];
					minJ = res[j];
					minK = res[k];
				
					min = abs((res[i] + res[j] + res[k]) / 3 - p);
				}
			}
		}
	}	
	
	printf("(%d + %d + %d)/3 = %d\n", minI, minJ, minK, (minI + minJ + minK) / 3);
	
	return 0;
}

int abs(int n) {
	if(n < 0) {
		n *= -1;
	}

	return n;
}
