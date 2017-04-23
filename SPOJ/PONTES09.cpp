// http://br.spoj.com/problems/PONTES09/

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <limits>

int calculateJumps(
    const std::vector<std::vector<std::pair<int, int>>>& graph,
    const int source,
    const int target) {
  std::vector<int> jumps(graph.size(), std::numeric_limits<int>::max());
  jumps[source] = 0;

  std::set<std::pair<int, int>> to_visit;
  to_visit.insert(std::make_pair(0, source));

  while (!to_visit.empty()) {
    int vertex = to_visit.begin()->second;
    if (vertex == target) break;
    to_visit.erase(to_visit.begin());

    for (size_t i = 0; i < graph[vertex].size(); ++i) {
      int neighbor = graph[vertex][i].first;
      int cost = graph[vertex][i].second;
      if (jumps[neighbor] > jumps[vertex] + cost) {
        jumps[neighbor] = jumps[vertex] + cost;
        to_visit.insert(std::make_pair(jumps[neighbor], neighbor));
      }
    }
  }
  return jumps[target];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> graph(n+2);
  while (m-- > 0) {
    int s, t, b;
    std::cin >> s >> t >> b;
    graph[s].push_back(std::make_pair(t, b));
    graph[t].push_back(std::make_pair(s, b));
  }
  std::cout << calculateJumps(graph, 0, n+1) << std::endl;
  return 0;
}
