// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=761

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int kInf = 100000000;

int maxFlow(const int source, const int sink,
            const std::vector<std::vector<int>>& graph,
            std::vector<std::vector<int>>* flows) {
  int flow = 0;

  while (true) {
    std::vector<bool> visited(graph.size());
    std::vector<int> previous(graph.size(), -1);
    std::queue<int> to_visit;
    to_visit.push(source);
    visited[source] = true;
    while (!to_visit.empty()) {
      int current = to_visit.front();
      to_visit.pop();
      for (size_t i = 0; i < graph[current].size(); ++i) {
        int vertex = graph[current][i];
        if (!visited[vertex] && (*flows)[current][vertex] > 0) {
          visited[vertex] = true;
          previous[vertex] = current;
          to_visit.push(vertex);
          if (vertex == sink) break;
        }
      }
      if (previous[sink] != -1) break;
    }

    int capacity = kInf;
    int prev, current = sink;
    while (previous[current] != -1) {
      prev = previous[current];
      capacity = std::min(capacity, (*flows)[prev][current]);
      current = prev;
    }

    current = sink;
    while (previous[current] != -1) {
      prev = previous[current];
      (*flows)[prev][current] -= capacity;
      (*flows)[current][prev] += capacity;
      current = prev;
    }

    if (capacity == kInf) break;
    flow += capacity;
  }

  return flow;
}

int main() {
  int n, network = 0;
  std::cin >> n;
  while (n != 0) {
    std::vector<std::vector<int>> flows(n, std::vector<int>(n));
    std::vector<std::vector<int>> graph(n);

    int s, t, c;
    std::cin >> s >> t >> c;
    while (c-- > 0) {
      int i, j, f;
      std::cin >> i >> j >> f;
      --i, --j;
      flows[i][j] += f;
      flows[j][i] += f;
      graph[i].push_back(j);
      graph[j].push_back(i);
    }

    std::cout << "Network " << ++network << std::endl;
    std::cout << "The bandwidth is "
      << maxFlow(--s, --t, graph, &flows) << "." << std::endl;
    std::cout << std::endl;

    std::cin >> n;
  }
  return 0;
}
