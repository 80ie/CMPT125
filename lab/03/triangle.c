#include <stdio.h>
#include <assert.h>

int sum_to(int n){
  if (n <= 1){
    return 1;
  }
  return n + sum_to(n-1);
}

int power(int base, int exp) {
  assert(exp >=0);
  if (exp <= 1) {
    return exp ? base : 1;
  }
  return base * power(base, exp -1);
}

int main() {
  printf("sum_to(%d) = %d\n\n", 100, sum_to(100));

  int base = 5;
  for (int i = 0; i <= 10; i++) {
    printf("%d^%d = %d\n", 5, 0, power(base,i));
  }

}
