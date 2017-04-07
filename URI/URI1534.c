// https://www.urionlinejudge.com.br/judge/en/problems/view/1534

#include <stdio.h>

#define MAX_SIZE 70

void initializeMatrix(int matrix[][MAX_SIZE], const int size) {
  int i, j;
  for (i = 0; i < size; ++i)
    for (j = 0; j < size; ++j)
      matrix[i][j] = 3;
}

void printMatrix(int matrix[][MAX_SIZE], const int size) {
  int i, j;
  for (i = 0; i < size; ++i) {
    for (j = 0; j < size; ++j)
      printf("%d", matrix[i][j]);
    printf("\n");
  }
}

int main() {
  int n, i, matrix[MAX_SIZE][MAX_SIZE];

  while ((scanf("%d", &n)) != EOF) {
    initializeMatrix(matrix, n);

    for (i = 0; i < n/2.0; ++i) {
      matrix[i][i] = 1;
      matrix[n-i-1][n-i-1] = 1;
      matrix[i][n-i-1] = 2;
      matrix[n-i-1][i] = 2;
    }

    printMatrix(matrix, n);
  }

  return 0;
}
