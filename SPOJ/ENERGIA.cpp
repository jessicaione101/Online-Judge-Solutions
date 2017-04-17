// http://br.spoj.com/problems/ENERGIA/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

bool isNormal(const std::vector<std::vector<int>>& map) {
  for (size_t i = 0; i < map.size(); ++i) {
    std::vector<bool> visited(map.size());
    std::stack<int> to_visit;
    to_visit.push(i);
    while (!to_visit.empty()) {
      int station = to_visit.top();
      to_visit.pop();
      if (!visited[station]) {
        visited[station] = true;
        for (size_t j = 0; j < map[station].size(); ++j)
          to_visit.push(map[station][j]);
      }
    }
    if (std::find(visited.begin(), visited.end(), false) != visited.end())
      return false;
  }
  return true;
}

int main() {
  int e, l, test = 0;
  std::cin >> e >> l;
  while (e != l || l != 0) {
    std::vector<std::vector<int>> map(e);
    while (l-- > 0) {
      int x, y;
      std::cin >> x >> y;
      map[x-1].push_back(y-1);
      map[y-1].push_back(x-1);
    }

    std::cout << "Teste " << ++test << std::endl;
    if (isNormal(map))
      std::cout << "normal";
    else
      std::cout << "falha";
    std::cout << std::endl << std::endl;;
    std::cin >> e >> l;
  }
  return 0;
}
