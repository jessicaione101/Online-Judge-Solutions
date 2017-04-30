// http://www.spoj.com/problems/IM/

#include <iostream>
#include <vector>
#include <utility>

bool depthFirstSearch(const int source, const int destination,
                      std::vector<std::vector<std::pair<int, bool> > >* graph,
                      std::vector<bool>* visited) {
  if (source == destination)
    return true;
  if ((*visited)[source])
    return false;
  (*visited)[source] = true;

  for (size_t i = 0; i < (*graph)[source].size(); ++i) {
    if ((*graph)[source][i].second) {
      (*graph)[source][i].second = false;
      int next = (*graph)[source][i].first;
      if (depthFirstSearch(next, destination, graph, visited))
        return true;
      (*graph)[source][i].second = true;
    }
  }

  return false;
}

int main() {
  int t;
  std::cin >> t;
  while (t-- > 0) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, bool> > > graph(n+1);

    while (m-- > 0) {
      int i, j;
      std::cin >> i >> j;
      if (i > 0 && i <= n && j > 0 && j <= n) {
        --i, --j;
        graph[i].push_back(std::make_pair(j, true));
        graph[j].push_back(std::make_pair(i, true));
      }
    }

    if (n < 3) {
      std::cout << "NO" << std::endl;
      continue;
    }

    std::vector<bool> visited(n);
    if (depthFirstSearch(1, 0, &graph, &visited)) {
      visited.clear();
      visited.resize(n);
      if (depthFirstSearch(1, 2, &graph, &visited)) {
        std::cout << "YES" << std::endl;
        continue;
      }
    }
    std::cout << "NO" << std::endl;
  }
  return 0;
}
