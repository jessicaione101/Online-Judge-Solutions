// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2501

#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
  int m, w;
  std::cin >> m >> w;
  while (m != w || m != 0) {
    int size = 2 * m - 2;
    std::vector<std::vector<int>> flows(size, std::vector<int>(size));
    std::vector<std::vector<int>> graph(size);
    std::map<int, int> vertices;

    vertices[0] = 0;
    for (int i = 1; i < m; ++i)
      vertices[i] = 2 * i - 1;

    for (int j = 0; j < m-2; ++j) {
      int i, c;
      std::cin >> i >> c;
      --i;
      i = vertices[i];
      flows[i][i+1] = c;
      graph[i].push_back(i+1);
      graph[i+1].push_back(i);
    }

    while (w-- > 0) {
      int j, k, d;
      std::cin >> j >> k >> d;
      --j, --k;

      int u1 = vertices[j], v1 = u1+1;
      int u2 = vertices[k], v2 = u2+1;
      if (j == 0 || j == m-1)
        v1 = u1;
      if (k == 0 || k == m-1)
        v2 = u2;

      flows[v1][u2] = d;
      flows[v2][u1] = d;
      graph[v1].push_back(u2);
      graph[u2].push_back(v1);
      graph[v2].push_back(u1);
      graph[u1].push_back(v2);
    }

    std::cout << maxFlow(0, size-1, graph, &flows) << std::endl;
    std::cin >> m >> w;
  }
  return 0;
}
