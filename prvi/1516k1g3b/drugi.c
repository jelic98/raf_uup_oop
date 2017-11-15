#include <stdio.h>

int isdigit(char);
int max(int, int);
int abs(int);

int main() {
	int found = 0, curr = 0, prev = 0, res = 0;
	char c;

	while((c = getchar()) != EOF) {
		curr = 0;

		while((c = getchar()) != EOF && isdigit(c)) {
			curr *= 10;
			curr += c - '0';

			if(found == 0 || found == 2) {
				found++;
			}
		}

		if(!isdigit(c) && found == 1) {
			found++;
		}

		if(found >= 3) {	
			res = max(res, abs(curr - prev));
		}

		prev = curr;
		
		if(c == '\n') {
			break;
		}	
	}

	printf("%d\n", res);

	return 0;
}

int isdigit(char c) {
	return c >= '0' && c <= '9';
}

int max(int a, int b) {
	if(a > b) {
		return a;
	}

	return b;
}

int abs(int n) {
	if(n < 0) {
		n *= -1;
	}

	return n;
}
