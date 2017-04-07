// http://br.spoj.com/problems/QUERM/

#include <stdio.h>

int main() {
  int n, i, j, test = 0;
  scanf("%d", &n);

  while (n != 0) {
    for (j = 0; j < n; ++j) {
      scanf("%d", &i);
      if (i == j+1) {
        printf("Teste %d\n%d\n\n", ++test, i);
      }
    }
    scanf("%d", &n);
  }

  return 0;
}
