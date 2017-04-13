// https://www.urionlinejudge.com.br/judge/en/problems/view/1542

#include <stdio.h>

int main() {
  int q, d, p;
  scanf("%d %d %d", &q, &d, &p);

  while (q != 0) {
    int pages = (q * p * d) / (p - q);

    if (pages > 1)
      printf("%d paginas\n", pages);
    else
      printf("%d pagina\n", pages);

    scanf("%d %d %d", &q, &d, &p);
  }

  return 0;
}
