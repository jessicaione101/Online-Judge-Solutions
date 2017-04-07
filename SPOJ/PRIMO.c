// http://br.spoj.com/problems/PRIMO/

#include <stdio.h>
#include <stdlib.h>

char* isPrime(const long int n) {
  if (n <= 1)
    return "nao";
  if (n <= 3)
    return "sim";
  if (n % 2 == 0 || n % 3 == 0)
    return "nao";

  long int divisor = 5;
  while (divisor*divisor <= n) {
    if (n % divisor == 0 || n % (divisor+2) == 0)
      return "nao";
    divisor += 6;
  }

  return "sim";
}

int main() {
  long int n;
  scanf("%ld", &n);
  printf("%s\n", isPrime(abs(n)));
  return 0;
}
