// http://br.spoj.com/problems/MINHOCA/

#include <stdio.h>

#define MAX_SIZE 100

int maxSum(const int map[][MAX_SIZE], const int rows, const int cols) {
  int i, j, sum = 0, max_sum = 0;

  for (i = 0; i < rows; ++i) {
    for (j = 0; j < cols; ++j)
      sum += map[i][j];
    if (sum > max_sum)
      max_sum = sum;
    sum = 0;
  }

  for (j = 0; j < cols; ++j) {
    for (i = 0; i < rows; ++i)
      sum += map[i][j];
    if (sum > max_sum)
      max_sum = sum;
    sum = 0;
  }

  return max_sum;
}

int main() {
  int n, m, map[MAX_SIZE][MAX_SIZE];
  scanf("%d %d", &n, &m);

  int i, j;
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j)
      scanf("%d", &map[i][j]);

  printf("%d\n", maxSum(map, n, m));

  return 0;
}
