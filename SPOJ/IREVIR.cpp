// http://br.spoj.com/problems/IREVIR/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

bool isConnected(const std::vector<std::vector<int>>& map) {
  for (size_t i = 0; i < map.size(); ++i) {
    std::vector<bool> visited(map.size());
    std::queue<int> to_visit;
    to_visit.push(i);
    while (!to_visit.empty()) {
      int intersection = to_visit.front();
      to_visit.pop();
      if (!visited[intersection]) {
        visited[intersection] = true;
        for (size_t j = 0; j < map[intersection].size(); ++j)
          to_visit.push(map[intersection][j]);
      }
    }
    if (std::find(visited.begin(), visited.end(), false) != visited.end())
      return false;
  }
  return true;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  while (n != 0) {
    std::vector<std::vector<int>> map(n);
    while (m-- > 0) {
      int v, w, p;
      std::cin >> v >> w >> p;
      map[v-1].push_back(w-1);
      if (p > 1)
        map[w-1].push_back(v-1);
    }
    std::cout << isConnected(map) << std::endl;
    std::cin >> n >> m;
  }
  return 0;
}
