#include <stdio.h>

#define SIZE 100

void ispis(int[][SIZE], int);

int main() {
	int n, i, j, p, diff, count;
	int a[SIZE][SIZE] = {
		{1,4,5,6,7},	
		{5,6,7,8,9},	
		{8,9,4,3,2},	
		{9,4,1,3,7},	
		{8,6,6,4,1}	
	};

	//scanf("%d", &n);
	n = 5;

	//for(i = 0; i < n; i++) {
	//	for(j = 0; j < n; j++) {
	//		scanf("%d", &a[i][j]);
	//	}	
	//}

	count = 1;

	ispis(a, n);
	printf("\n");

	for(i = 1; i < n; i++) {
		int k = count;

		while(k-- > 0) {
			p = a[i][n - 1];

			for(j = n - 2; j >= 0; j--) {
				a[i][j + 1] = a[i][j];
			}	

			a[i][0] = p;
		}
	
		count = (count + 1) % n;
	}

	ispis(a, n);

	return 0;
}

void ispis(int a[][SIZE], int n) {
	int i, j;

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%2d", a[i][j]);
		}	
		
		printf("\n");
	}
}
