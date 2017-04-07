// http://br.spoj.com/problems/OBIHANOI/

#include <stdio.h>
#include <math.h>

int main() {
  int n, test = 0;
  long long int moves;
  scanf("%d", &n);

  while (n != 0) {
    moves = pow(2, n) - 1;
    printf("Teste %d\n%lld\n\n", ++test, moves);
    scanf("%d", &n);
  }

  return 0;
}
