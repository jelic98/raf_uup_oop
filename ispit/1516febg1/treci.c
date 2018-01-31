#include <stdio.h>

#define SIZE 100

int main() {
	char s[SIZE];
	int i = -1;

	scanf("%s", s);

	while(s[++i]) {
		if(i) {
			printf("-");
		}

		printf("%d", s[i] - 'A' + 1);
	}

	printf("\n");

	return 0;
}
