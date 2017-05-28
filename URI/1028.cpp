// https://www.urionlinejudge.com.br/judge/en/problems/view/1028

#include <iostream>

int gcd(int a, int b) {
  int temp;
  while (b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main() {
  int n, f1, f2;
  std::cin >> n;
  while (n-- > 0) {
    std::cin >> f1 >> f2;
    std::cout << gcd(f1, f2) << std::endl;
  }
  return 0;
}
