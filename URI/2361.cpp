// https://www.urionlinejudge.com.br/judge/en/problems/view/2361

#include <iostream>

int main() {
  int n, k;
  std::cin >> n >> k;
  while (n != 0 || k != 0) {
    if (k == 1) {
      for (int i = n; i > 1; --i)
        std::cout << i << " ";
      std::cout << 1;
    } else {
      for (int i = 1; i < k; ++i)
        std::cout << i << " ";
      for (int i = n; i > k; --i)
        std::cout << i << " ";
      std::cout << k;
    }
    std::cout << std::endl;
    std::cin >> n >> k;
  }
  return 0;
}
