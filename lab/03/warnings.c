#include <stdio.h>

int no_return(int n) {
  if (n > 0) {
    return n;
  }
}

int unused_param(int a, int b) {
  return a;
}

int main() {
  int unused = 42;
  int uninit;
  unsigned int u = 3;
  int i = -1;

  if (i < u) {
    printf("-1 < 3u\n");
  }

  printf("%d\n", uninit);
  printf("%d\n", 3.14);
  printf("%s\n", 7);

  return no_return(1) + unused_param(1, 2);
}
