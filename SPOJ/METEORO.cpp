// http://br.spoj.com/problems/METEORO/

#include <iostream>

int main() {
  int x1, y1, x2, y2, test = 0;
  std::cin >> x1 >> y1 >> x2 >> y2;
  while (x1 != 0 || y1 != 0 || x2 != 0 || y2 != 0) {
    int n;
    std::cin >> n;

    int x, y, counter = 0;
    while (n-- > 0) {
      std::cin >> x >> y;
      if (x >= x1 && x <= x2 && y <= y1 && y >= y2)
        ++counter;
    }

    std::cout << "Teste " << ++test << std::endl;
    std::cout << counter << std::endl << std::endl;

    std::cin >> x1 >> y1 >> x2 >> y2;
  }

  return 0;
}
