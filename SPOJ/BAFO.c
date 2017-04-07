// http://br.spoj.com/problems/BAFO/

#include <stdio.h>

char* winner(const int aldo, const int beto) {
  if (aldo > beto)
    return "Aldo";
  return "Beto";
}

int main() {
  int r, a, b;
  int aldo = 0, beto = 0, test = 0;
  scanf("%d", &r);
  while (r != 0) {
    while (r-- > 0) {
      scanf("%d %d", &a, &b);
      aldo += a;
      beto += b;
    }
    printf("Teste %d\n%s\n", ++test, winner(aldo, beto));
    aldo = 0, beto = 0;
    scanf("%d", &r);
  }
  return 0;
}
