// https://www.urionlinejudge.com.br/judge/en/problems/view/2355

#include <iostream>
#include <cmath>

int main() {
  int64_t n;
  std::cin >> n;
  while (n != 0) {
    int a, b;
    a = ceil(n / 90.0 * 7);
    b = floor(n / 90.0);
    std::cout << "Brasil " << b << " x Alemanha " << a << std::endl;
    std::cin >> n;
  }
  return 0;
}
