// https://www.urionlinejudge.com.br/judge/en/problems/view/2357

#include <iostream>
#include <vector>

bool hasCycle(const std::vector<std::vector<int>>& graph,
    std::vector<bool>* visited,
    const int vertex,
    const int parent) {
  (*visited)[vertex] = true;

  for (size_t i = 0; i < graph[vertex].size(); ++i) {
    int neighbor = graph[vertex][i];

    if ((*visited)[neighbor] && neighbor != parent)
      return true;

    if (!(*visited)[neighbor]) {
      if (hasCycle(graph, visited, neighbor, vertex))
        return true;
    }
  }

  return false;
}

int main() {
  int n, m;
  while (std::cin >> n >> m) {
    std::vector<std::vector<int>> graph(n);
    int a, b;
    while (m-- > 0) {
      std::cin >> a >> b;
      --a, --b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    bool has_cycle = false;
    std::vector<bool> visited(graph.size());
    for (size_t i = 0; i < graph.size(); ++i) {
      if (!visited[i]) {
        if (hasCycle(graph, &visited, i, -1)) {
          has_cycle = true;
          break;
        }
      }
    }

    if (has_cycle)
      std::cout << "Inseguro";
    else
      std::cout << "Seguro";
    std::cout << std::endl;
  }

  return 0;
}
