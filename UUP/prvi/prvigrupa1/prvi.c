#include <stdio.h>

int pom(int);
int abs(int);
int max(int, int);

int main() {
	int min, max;

	scanf("%d%d", &min, &max);
	
	while(min++ <= max) {
		if(pom(min - 1) > 3) {
			printf("%d\n", min - 1);	
		}
	}

	return 0;	
}

int pom(int arg) {
	int count = 0, res = 0;

	while((count++ > 0) ? res = max(res, abs(arg % 10 - arg % 100 / 10)), arg /= 10: res, arg > 0);

	return res;
}

int abs(int arg) {
	return (arg >= 0) ? arg : arg * (-1);
}

int max(int arg1, int arg2) {
	return (arg1 > arg2) ? arg1 : arg2;
}
