#include <cstdio>
#include <cstdlib>

long long xeuclid(long long a, long long b, long long x[], long long y[]) {
  long long q, r, xx, yy, sign;

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

  return a;
}

int main() {
  long long a, b, x[100], y[100];
  printf("Please enter first integer:");
  scanf("%lld", &a);
  printf("Please enter second integer:");
  scanf("%lld", &b);

  if (a < b) {
    long long temp = a;
    a = b;
    b = temp;
  }

  long long r = xeuclid(a, b, x, y);

  printf("The greatest common divisor of %lld and %lld is %lld.\n", a, b, r);
  printf("%lld = %lld * %lld + %lld * %lld.", r, x[0], a, y[0], b);
  
  return 0;
}
