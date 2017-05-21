// http://br.spoj.com/problems/POODLEMG/

#include <iostream>
#include <string>
#include <cmath>

int main() {
  int n, p;
  std::cin >> n >> p;
  while (n != 0 || p != 0) {
    std::string logo = "Poo";
    int pages = ceil(n / static_cast<double>(p));

    int size = fmin(pages-6, 14);
    for (int i = size; i > 0; --i)
      logo += 'o';

    logo += "dle";
    std::cout << logo << std::endl;

    std::cin >> n >> p;
  }

  return 0;
}
