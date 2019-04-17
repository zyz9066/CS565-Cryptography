#include <cstdio>

unsigned long long pow(unsigned long long base, unsigned long long exponent, unsigned long long mod) {
  
  unsigned long long result = 1;

  while (exponent > 0) {
    if (exponent%2 != 0) {
      result *= base;
      result %= mod;
    }
    base *= base;
    base %= mod;
    exponent /= 2;
  }
  return result;
}

int main() {

  unsigned long long a, e, m;
  printf("Please enter the base: ");
  scanf("%lld", &a);
  printf("Please enter the exponent: ");
  scanf("%lld", &e);
  printf("Please enter the modulo: ");
  scanf("%lld", &m);

  printf("The result is %lld.", pow(a, e, m));
  return 0;
}
