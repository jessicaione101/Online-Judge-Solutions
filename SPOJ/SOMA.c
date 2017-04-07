// http://br.spoj.com/problems/SOMA/

#include <stdio.h>

int main() {
  int n, x, i, sum = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &x);
    sum += x;
  }
  printf("%d\n", sum);
  return 0;
}
