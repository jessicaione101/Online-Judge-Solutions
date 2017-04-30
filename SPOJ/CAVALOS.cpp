// http://br.spoj.com/problems/CAVALOS/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

bool depthFirstSearch(const int source, const int sink,
                      const std::vector<std::vector<int>>& capacity,
                      std::vector<std::vector<int>>* flow,
                      std::vector<bool>* visited) {
  if (source == sink)
    return true;
  for (size_t i = 0; i < capacity.size(); ++i) {
    if (!(*visited)[i] && capacity[source][i] - (*flow)[source][i] > 0) {
      (*visited)[source] = true;
      if (depthFirstSearch(i, sink, capacity, flow, visited)) {
        ++(*flow)[source][i];
        --(*flow)[i][source];
        return true;
      }
      (*visited)[source] = false;
    }
  }
  return false;
}

int maxMatching(const int source, const int sink,
                const std::vector<std::vector<int>>& capacity) {
  int matching = 0;
  std::vector<std::vector<int>>
    flow(capacity.size(), std::vector<int>(capacity.size()));
  std::vector<bool> visited(capacity.size());
  while (depthFirstSearch(source, sink, capacity, &flow, &visited)) {
    ++matching;
    visited.clear();
    visited.resize(capacity.size());
  }
  return matching;
}

int main() {
  int n, m, k, instance = 0;
  while (std::cin >> n >> m >> k) {
    std::vector<std::vector<int>> capacity(n+m+2, std::vector<int>(n+m+2));

    int c;
    for (int i = 1; i <= n; ++i) {
      std::cin >> c;
      capacity[m+i][n+m+1] = c;
    }

    int u, v;
    while (k-- > 0) {
      std::cin >> u >> v;
      capacity[v][m+u] = 1;
    }

    for (int i = 1; i <= m; ++i) {
      capacity[0][i] = 1;
    }

    std::cout << "Instancia " << ++instance << std::endl;
    std::cout << maxMatching(0, n+m+1, capacity) << std::endl;
    std::cout << std::endl;
  }
  return 0;
}
