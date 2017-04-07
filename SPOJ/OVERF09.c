// http://br.spoj.com/problems/OVERF09/

#include <stdio.h>

char* outputForSum(const int n, const int p, const int q) {
  if (p > n || q > n)
    return "OVERFLOW";
  if (q <= n-p)
    return "OK";
  return "OVERFLOW";
}

char* outputForMultiplication(const int n, const int p, const int q) {
  if (p > n || q > n) {
    if (p == 0 || q == 0)
      return "OK";
    return "OVERFLOW";
  }

  if (p > q) {
    if (n/p >= q)
      return "OK";
  } else {
    if (n/q >= p)
      return "OK";
  }

  return "OVERFLOW";
}

int main() {
  int n, p, q;
  char c;
  scanf("%d\n%d %c %d", &n, &p, &c, &q);

  if (c == '+')
    printf("%s\n", outputForSum(n, p, q));
  else
    printf("%s\n", outputForMultiplication(n, p, q));

  return 0;
}
