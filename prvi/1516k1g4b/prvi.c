#include <stdio.h>

int fun(int);

int main() {
	int res, n, i, j, out[100];

	res = 0;
	i = -1;

	do {
		scanf("%d", &n);

		if(n != 0) {
			i++;

			out[i] = fun(n);
			res += out[i] * n;
		}
	}while(n != 0);

	printf("%d", res);

	if(res > 0) {
		printf(" ");
	}

	if(i > 0) {
		printf("(");

		for(j = 0; j <= i; j++) {	
			printf("%s%s", (out[j] == 1) ? "DA" : "NE", (j < i) ? ", " : "");
		}

		printf(")");
	}

	printf("\n");

	return 0;	
}

int fun(int n) {
	int count = 0;

	while(n > 0) {
		if((n % 10) % 2 != 0) {
			count++;	
		}

		n /= 10;
	}

	return count > 0 && count % 2 == 0;
}
