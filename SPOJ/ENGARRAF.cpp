// http://br.spoj.com/problems/ENGARRAF/

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <limits>

int calculateDistance(
    const std::vector<std::vector<std::pair<int, int>>>& graph,
    const int source,
    const int target) {
  std::vector<int> distance(graph.size(), std::numeric_limits<int>::max());
  distance[source] = 0;

  std::set<std::pair<int, int>> to_visit;
  to_visit.insert(std::make_pair(0, source));

  while (!to_visit.empty()) {
    int vertex = to_visit.begin()->second;
    if (vertex == target)
      return distance[vertex];
    to_visit.erase(to_visit.begin());

    for (size_t i = 0; i < graph[vertex].size(); ++i) {
      int neighbor = graph[vertex][i].first;
      int cost = graph[vertex][i].second;
      if (distance[neighbor] > distance[vertex] + cost) {
        distance[neighbor] = distance[vertex] + cost;
        to_visit.insert(std::make_pair(distance[neighbor], neighbor));
      }
    }
  }
  return -1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  while (n != 0 || m != 0) {
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    while (m-- > 0) {
      int i, j, t;
      std::cin >> i >> j >> t;
      graph[i-1].push_back(std::make_pair(j-1, t));
    }
    int s, d;
    std::cin >> s >> d;
    std::cout << calculateDistance(graph, s-1, d-1) << std::endl;
    std::cin >> n >> m;
  }
  return 0;
}
