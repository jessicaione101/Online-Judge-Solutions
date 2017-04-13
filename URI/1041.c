// https://www.urionlinejudge.com.br/judge/en/problems/view/1041

#include <stdio.h>

char* quadrant(const float x, const float y) {
  if (x != 0 && y == 0)
    return "Eixo X";
  if (x == 0 && y != 0)
    return "Eixo Y";
  if (x > 0 && y > 0)
    return "Q1";
  if (x < 0 && y > 0)
    return "Q2";
  if (x < 0 && y < 0)
    return "Q3";
  if (x > 0 && y < 0)
    return "Q4";
  return "Origem";
}

int main() {
  float x, y;
  scanf("%f %f", &x, &y);
  printf("%s\n", quadrant(x, y));
  return 0;
}
