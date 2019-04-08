#include <cstdio>
#include <cstdlib>

int euclid(int a, int b) {
  int r;
  a = abs(a);
  b = abs(b);

  if (a < b) {
    int temp = a;
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
  int a, b;
  printf("Please enter first integer:");
  scanf("%d", &a);
  printf("Please enter second integer:");
  scanf("%d", &b);
  printf("The greatest common divisor of %d and %d is %d.", a, b, euclid(a, b));
}