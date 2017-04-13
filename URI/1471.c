// https://www.urionlinejudge.com.br/judge/en/problems/view/1471

#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

int main() {
  int i, n, r, volunteer, returned[10000];

  while ((scanf("%d %d", &n, &r) != EOF)) {
    if (r == n) {
      printf("*\n");
      for (i = 0; i < r; ++i)
        scanf("%d", &volunteer);
      continue;
    }

    memset(returned, FALSE, sizeof(int)*n);
    for (i = 0; i < r; ++i) {
      scanf("%d", &volunteer);
      returned[volunteer-1] = TRUE;
    }

    for (i = 0; i < n; ++i) {
      if (!returned[i])
        printf("%d ", i+1);
    }
    printf("\n");
  }

  return 0;
}
