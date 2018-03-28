#include <stdio.h>

#define SIZE 100
#define N 9
#define S 3

int proveri(int[][SIZE]);

int main() {
	int i, j, a[SIZE][SIZE];

	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	printf("%d\n", proveri(a));

	return 0;
}

int proveri(int a[][SIZE]) {
	int res = 0, i, j, k, q, xK, yK, xQ, yQ;
	
	for(i = 0; i + S <= N; i += S) {
		for(j = 0; j + S <= N; j += S) {
			for(k = 0; k < N; k++) {
				xK = i + k / S;
				yK = j + k % S;

				for(q = 0; q < N; q++) {	
					xQ = i + k / S;
					yQ = j + k % S;

					if(xK == xQ && yK == yQ) {
						continue;	
					}

					if(a[xK][xQ] == a[yK][yQ]) {
						res = 1;
						break;
					}
				}
			
				if(res) {
					break;
				}
			}

			if(res) {
				break;
			}
		}

		if(res) {
			break;
		}
	}

	return !res;
}
