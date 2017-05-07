// http://br.spoj.com/problems/TESOURO/

#include <iostream>
#include <vector>
#include <cstdlib>

bool isDivisible(const std::vector<int>& chest,
    const int treasure, const int to_divide) {
  if (chest.size() < 2 || to_divide % 2 != 0)
    return false;

  int half = to_divide / 2;
  std::vector<int> division(treasure+1);
  division[0] = true;

  for (size_t i = 0; i < chest.size(); ++i) {
    for (int j = treasure; j >= chest[i]; --j)
      division[j] |= division[j - chest[i]];
  }

  return division[half];
}

int main() {
  int x, y, n, test = 0;
  std::cin >> x >> y >> n;
  while (x != 0 || y != 0 || n != 0) {
    std::vector<int> chest(n);
    int v, treasure = 0;
    for (int i = 0; i < n; ++i) {
      std::cin >> v;
      chest[i] = v;
      treasure += v;
    }

    int to_divide = treasure - abs(x - y);
    bool is_divisible = false;
    is_divisible = (to_divide == 0) || isDivisible(chest, treasure, to_divide);

    std::cout << "Teste " << ++test << std::endl;
    if (is_divisible)
      std::cout << "S" << std::endl;
    else
      std::cout << "N" << std::endl;
    std::cout << std::endl;

    std::cin >> x >> y >> n;
  }

  return 0;
}
