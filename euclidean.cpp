#include <cstdio>
#include <cstdlib>

long euclid(long a, long b) {
  long r;
  a = abs(a);
  b = abs(b);

  if (a < b) {
    long temp = a;
    a = b;
    b = temp;
  }
  

  while (b != 0) {
    r = a%b;
    a = b;
    b = r;
  }

  return a;
}

int main() {
  long a, b;
  printf("Please enter first integer:");
  scanf("%ld", &a);
  printf("Please enter second integer:");
  scanf("%ld", &b);
  printf("The greatest common divisor of %ld and %ld is %ld.", a, b, euclid(a, b));
  
  return 0;
}
