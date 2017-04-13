// https://www.urionlinejudge.com.br/judge/en/problems/view/1080

#include <stdio.h>

int main() {
  int i, n, highest, position = 1;
  scanf("%d", &highest);

  for (i = 1; i < 100; ++i) {
    scanf("%d", &n);
    if (n > highest) {
      highest = n;
      position = i+1;
    }
  }

  printf("%d\n%d\n", highest, position);
  return 0;
}
