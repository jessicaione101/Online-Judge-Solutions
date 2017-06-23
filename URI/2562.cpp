// https://www.urionlinejudge.com.br/judge/en/problems/view/2562

#include <iostream>
#include <vector>
#include <algorithm>

void species(const int source,
           const std::vector<std::vector<int>>& manual,
           std::vector<bool>* visited) {
  for (size_t i = 0; i < manual[source].size(); ++i) {
    int specie = manual[source][i];
    if (!(*visited)[specie]) {
      (*visited)[specie] = true;
      species(specie, manual, visited);
    }
  }
}

int main() {
  int n, m;
  while (std::cin >> n >> m) {
    std::vector<std::vector<int>> manual(n);

    int a, b;
    while (m-- > 0) {
      std::cin >> a >> b;
      --a, --b;
      manual[a].push_back(b);
      manual[b].push_back(a);
    }

    int e;
    std::cin >> e;
    --e;

    std::vector<bool> visited(n);
    visited[e] = true;
    species(e, manual, &visited);

    std::cout << std::count(visited.begin(), visited.end(), true) << std::endl;
  }

  return 0;
}
