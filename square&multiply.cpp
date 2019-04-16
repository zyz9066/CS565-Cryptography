#include <stdio.h>
#include <stdlib.h>

long sma(long x,  long c,  long n){

	unsigned long long z = 1;
	int b[100];
	int i = 0;

	// convert c to binary
	while(c > 0) {
		if(c % 2 == 0) {
			b[i] = 0;
		} else {
			b[i] = 1;
		}

		c /= 2;
		++i;
	}

	for(--i; i >= 0; --i) {
		z = (z * z) % n;

		if(b[i] == 1) {
			z = (z * x) % n;
		}
	}

	return z;
}


int main() {

	long x, c, n; //input

	// reading
	printf("Please enter the plaintext: ");
	scanf("%ld", &x);
	printf("Please enter the exponent: ");
	scanf("%ld", &c);
	printf("Please enter the modular: ");
	scanf("%ld", &n);

	long y = sma(x, c, n); //Square-and-Multiply modular Exponentation

  	// output
	printf("The ciphertext is %ld.\n", y);	

	return 0;
}
