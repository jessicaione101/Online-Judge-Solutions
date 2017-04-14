// https://www.urionlinejudge.com.br/judge/en/problems/view/1961

#include <iostream>
#include <cstdlib>

int main() {
  int p, n, pipe, height;
  std::cin >> p >> n >> height;
  while (--n > 0) {
    std::cin >> pipe;
    if (abs(pipe-height) > p) {
      std::cout << "GAME OVER" << std::endl;
      return 0;
    }
    height = pipe;
  }
  std::cout << "YOU WIN" << std::endl;
  return 0;
}
