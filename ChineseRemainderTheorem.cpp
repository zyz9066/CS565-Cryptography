#include <stdio.h>
#include <stdlib.h>

long long xgcd_left(long long a, long long b) {
    long long q, r, xx, yy, sign, x[100], y[100];

    // Initializes the coefficients

    x[0] = 1; x[1] = 0;
    y[0] = 0; y[1] = 1;
    sign = 1;
    
    // As long as b != 0 we replace a by b and b by a%b.
    // We also update the coefficients x and y.

    while (b != 0) {
        r = a%b;
        q = a/b;
        a = b;
        b = r;
        xx = x[1];
        yy = y[1];
        x[1] = q*x[1] + x[0];
        y[1] = q*y[1] + y[0];
        x[0] = xx;
        y[0] = yy;
        sign = -sign;
    }
    // Final computation of the coefficients

    x[0] = sign*x[0];
    y[0] = -sign*y[0];

    // Return gcd(a,b)

    return x[0];
}

long long crtPrecomputation(long long moduli[], long long multiplier[], int number) {
    int i;
    long long modulus = 1;
    long long m;
    long long M;
    long long inverse;

    for(i = 0; i < number; i++) modulus *= moduli[i];

    for(i = 0; i < number; i++) {
        m = moduli[i];
        M = modulus/m;
        inverse = xgcd_left(M, m);
        multiplier[i] = inverse * M % modulus;
    }
    return modulus;
}

long long crt(long long moduli[], long long x[], int number) {
    long long multiplier[number];
    long long result = 0;
    long long modulus = crtPrecomputation(moduli, multiplier, number);

    int i;

    for(i = 0; i < number; i++)
        result = (result + multiplier[i] * x[i]) % modulus;

    return result > 0 ? result : result + modulus;
}

int main() {
    long long x[100], moduli[100], X;
    int i, number;
    printf("Please enter the number of congruence:");
    scanf("%d", &number);
    for(i = 0; i < number; i++) {
        printf("Please enter a%d and m%d (whitespaced two number):", i, i);
        scanf("%lld %lld", &x[i], &moduli[i]);
    }

    X = crt(moduli, x, number);

    printf("The X is %lld.\n", X);
    
    return 0;
}
