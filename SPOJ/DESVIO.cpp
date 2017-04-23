// http://br.spoj.com/problems/DESVIO/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>
#include <functional>

int calculateToll(
    const std::vector<std::vector<std::pair<int, int>>>& graph,
    const int source,
    const int target) {
  std::vector<int> distance(graph.size(), std::numeric_limits<int>::max());
  distance[source] = 0;
  std::vector<bool> visited(graph.size());
  visited[source] = true;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
    std::greater<std::pair<int, int>>> to_visit;
  to_visit.push(std::make_pair(0, source));

  while (!to_visit.empty()) {
    int vertex = to_visit.top().second;
    if (vertex == target) break;
    to_visit.pop();
    visited[vertex] = true;

    for (size_t i = 0; i < graph[vertex].size(); ++i) {
      int neighbor = graph[vertex][i].first;
      int cost = graph[vertex][i].second;
      if (!visited[neighbor]) {
        if (distance[neighbor] > distance[vertex] + cost) {
          distance[neighbor] = distance[vertex] + cost;
          to_visit.push(std::make_pair(distance[neighbor], neighbor));
        }
      }
    }
  }
  return distance[target];
}

int main() {
  int n, m, c, k;
  std::cin >> n >> m >> c >> k;
  while (n != 0 || m != 0 || c != 0 || k != 0) {
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    while (m-- > 0) {
      int u, v, p;
      std::cin >> u >> v >> p;
      if (v < c && u == v-1) {
        graph[u].push_back(std::make_pair(v, p));
      } else if (u < c && v == u-1) {
        graph[v].push_back(std::make_pair(u, p));
      } else if (u < c && v >= c) {
        graph[v].push_back(std::make_pair(u, p));
      } else if (v < c && u >= c) {
        graph[u].push_back(std::make_pair(v, p));
      } else if (u >= c && v >= c) {
        graph[u].push_back(std::make_pair(v, p));
        graph[v].push_back(std::make_pair(u, p));
      }
    }
    std::cout << calculateToll(graph, k, c-1) << std::endl;
    std::cin >> n >> m >> c >> k;
  }
  return 0;
}
