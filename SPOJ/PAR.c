// http://br.spoj.com/problems/PAR/

#include <stdio.h>

int main() {
  char players[2][11];
  int n, a, b, test = 0;

  scanf("%d", &n);
  while (n != 0) {
    scanf("%s", players[0]);
    scanf("%s", players[1]);
    printf("Teste %d\n", ++test);

    while (n-- > 0) {
      scanf("%d %d", &a, &b);
      printf("%s\n", players[(a+b)%2]);
    }

    printf("\n");
    scanf("%d", &n);
  }

  return 0;
}
