#include <stdio.h>

double funi(int, char*);
double funr(int, int, char*);

int main() {
	char* s;

	scanf("%s", s);

	int n = -1;

	while(n++, *s++);

	s -= n + 1;

	printf("%lf\n", funi(n, s));
	printf("%lf\n", funr(0, n, s));

	return 0;
}

double funi(int n, char* s) {
	double sum;
	int i;

	for(i = n - 1; i >= 0; i--) {
		if(i == n - 1) {
			sum = s[i] - 'A' + 1;
		}else {
			sum = s[i] - 'A' + 1 + 1 / sum;	
		}
	}

	return sum;	
}

double funr(int i, int n, char* s) {
	if(i == n - 1) {
		return s[i] - 'A' + 1;
	}
	
	return s[i] - 'A' + 1 + 1 / funr(i + 1, n, s);	
}
