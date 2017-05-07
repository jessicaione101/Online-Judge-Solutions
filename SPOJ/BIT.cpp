// http://br.spoj.com/problems/BIT/

#include <iostream>
#include <map>
#include <vector>

int main() {
  std::map<int, int> bills = {{0, 50}, {1, 10}, {2, 5}, {3, 1}};
  int v, test = 0;
  std::cin >> v;
  while (v != 0) {
    std::vector<int> withdrawal(4);
    int i = 0;
    while (v > 0) {
      if (v >= bills[i]) {
        ++withdrawal[i];
        v -= bills[i];
      } else {
        ++i;
      }
    }

    std::cout << "Teste " << ++test << std::endl;
    std::cout << withdrawal[0] << " "
      << withdrawal[1] << " "
      << withdrawal[2] << " "
      << withdrawal[3] << std::endl;
    std::cout << std::endl;

    std::cin >> v;
  }

  return 0;
}
