// http://br.spoj.com/problems/RECUPERA/

#include <stdio.h>

#define FALSE 0
#define TRUE 1

int findSum(int n, const int instance) {
  int a, sum = 0;
  while (n-- > 0) {
    scanf("%d", &a);
    if (sum == a) {
      printf("Instancia %d\n%d\n\n", instance, a);
      while (n-- > 0)
        scanf("%d", &a);
      return TRUE;
    }
    sum += a;
  }
  return FALSE;
}

int main() {
  int n, instance = 0;

  while ((scanf("%d", &n)) != EOF) {
    if (!findSum(n, ++instance))
      printf("Instancia %d\nnao achei\n\n", instance);
  }

  return 0;
}
