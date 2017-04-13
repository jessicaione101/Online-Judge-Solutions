// https://www.urionlinejudge.com.br/judge/en/problems/view/1161

#include <stdio.h>

long long int sumFactorial(const int n1, const int n2) {
  long long int n1_factorial = 1, n2_factorial = 1;
  int i;

  for (i = 2; i <= n1; ++i)
    n1_factorial *= i;

  n2_factorial = n1_factorial;
  for (i = n1+1; i <= n2; ++i)
    n2_factorial *= i;

  return n1_factorial + n2_factorial;
}

int main() {
  int m, n;

  while ((scanf("%d %d", &m, &n)) != EOF) {
    if (m > n)
      printf("%lld\n", sumFactorial(n, m));
    else
      printf("%lld\n", sumFactorial(m, n));
  }

  return 0;
}
