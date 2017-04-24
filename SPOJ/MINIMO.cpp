// http://br.spoj.com/problems/MINIMO/

#include <iostream>
#include <algorithm>

const int kMax = 99999999;
int graph[200][200][200];

void calculateFlightCosts(int size) {
  for (int i = 1; i <= size; ++i) {
    for (int j = 0; j < size; ++j) {
      for (int k = 0; k < size; ++k)
        graph[i][j][k] =
          std::min(graph[i-1][j][k], graph[i-1][j][i-1] + graph[i-1][i-1][k]);
    }
  }
}

int main() {
  int n, m, test = 0;
  while (std::cin >> n >> m) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
          if (j == k)
            graph[i][j][k] = 0;
          else
            graph[i][j][k] = kMax;

    while (m-- > 0) {
      int u, v, w;
      std::cin >> u >> v >> w;
      graph[0][u-1][v-1] = std::min(graph[0][u-1][v-1], w);
    }

    calculateFlightCosts(n);

    std::cout << "Instancia " << ++test << std::endl;
    int c;
    std::cin >> c;
    while (c-- > 0) {
      int o, d, t;
      std::cin >> o >> d >> t;
      if (graph[t][o-1][d-1] < kMax)
        std::cout << graph[t][o-1][d-1] << std::endl;
      else
        std::cout << -1 << std::endl;
    }
    std::cout << std::endl;
  }
  return 0;
}
