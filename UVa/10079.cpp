// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1020

#include <iostream>

int main() {
  int64_t n;
  std::cin >> n;
  while (n >= 0) {
    std::cout << (n*n + n) / 2 + 1 << std::endl;
    std::cin >> n;
  }
  return 0;
}
