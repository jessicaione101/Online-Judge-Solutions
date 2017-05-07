// http://br.spoj.com/problems/MOEDAS/

#include <iostream>
#include <vector>

int main() {
  int m, n;
  std::cin >> m >> n;
  while (m != 0) {
    std::vector<int> coins(n);
    int v;
    for (int i = 0; i < n; ++i) {
      std::cin >> v;
      coins[i] = v;
    }

    std::vector<int> price(m+1, m+1);
    price[0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= m; ++j) {
        if (coins[i] <= j) {
          int value = j - coins[i];
          if (price[value] + 1 < price[j])
            price[j] = price[value] + 1;
        }
      }
    }

    if (price[m] == m+1)
      std::cout << "Impossivel";
    else
      std::cout << price[m];
    std::cout << std::endl;

    std::cin >> m >> n;
  }

  return 0;
}
