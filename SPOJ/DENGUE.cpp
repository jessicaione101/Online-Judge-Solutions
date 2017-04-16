// http://br.spoj.com/problems/DENGUE/

#include <iostream>
#include <vector>
#include <algorithm>

const int kMax = 10000;

int main() {
  int n, test = 0;
  std::cin >> n;
  while (n != 0) {
    std::vector<std::vector<int>> railroad(n, std::vector<int>(n, kMax));
    while (--n > 0) {
      int x, y;
      std::cin >> x >> y;
      railroad[x-1][y-1] = 1;
      railroad[y-1][x-1] = 1;
      railroad[x-1][x-1] = 0;
      railroad[y-1][y-1] = 0;
    }

    n = railroad.size();
    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j)
            if (railroad[i][j] > railroad[i][k] + railroad[k][j])
              railroad[i][j] = railroad[i][k] + railroad[k][j];

    int min = kMax, village = 0;
    for (int i = 0; i < n; ++i) {
      int max = *std::max_element(railroad[i].begin(), railroad[i].end());
      if (max < min) {
        min = max;
        village = i;
      }
    }

    std::cout << "Teste " << ++test << std::endl;
    std::cout << village+1 << std::endl;
    std::cout << std::endl;

    std::cin >> n;
  }
  return 0;
}
