#include <stdio.h>

int test(int);

int main() {
	int n, sum = 0;

	while(1) {
		scanf("%d", &n);
	
		if(test(n)) {
			sum += n;	
		}else {
//   			printf("%d", sum);
//   		break;
		}
	}

	return 0;
}

int test(int n) {
	int i, first, last, sum, count, mod;

	if(n == n % 100) {
		return 1;	
	}

	sum = 0;
	last = 0;
	count = 0;

	while(n > 0) {
		if(count == 2) {
			count = 0;
		}
		
		int mod = n % 10;

		for(i = 0; i < count; i++) {
			mod *= 10;
		}

		sum += mod;

		if(last == 0 && sum == sum % 100 && count++ > 0) {
			last = sum; 
		}
		
		if(n / 10 == 0) {
			first = mod * 10 + sum - mod;	
		}

		sum = mod;
		
		n /= 10;		
	}
	
	printf("%d + %d = %d\n", first, last, first == last);

	return first == last;
}
