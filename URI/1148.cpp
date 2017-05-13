// https://www.urionlinejudge.com.br/judge/en/problems/view/1148

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>

const int kMax = 1000;

int dijkstra(const std::vector<std::vector<int>>& graph,
             const int source, const int destination) {
  std::vector<int> distance(graph.size(), kMax);
  distance[source] = 0;
  std::vector<int> previous(graph.size(), -1);

  std::list<std::pair<int, size_t>> to_visit;
  for (size_t i = 0; i < graph.size(); ++i)
    to_visit.push_back(std::make_pair(distance[i], i));

  while (!to_visit.empty()) {
    to_visit.sort();
    int vertex = to_visit.front().second;
    to_visit.pop_front();

    if (vertex == destination)
      break;

    for (size_t i = 0; i < graph.size(); ++i) {
      if (graph[vertex][i] != -1) {
        int length = distance[vertex] + graph[vertex][i];
        if (length < distance[i]) {
          distance[i] = length;
          previous[i] = vertex;
          std::list<std::pair<int, size_t>>::iterator it;
          it = std::find_if(to_visit.begin(), to_visit.end(),
            [&i](const std::pair<int, size_t>& p) { return p.second == i; });
          if (it != to_visit.end())
            it->first = distance[i];
        }
      }
    }
  }

  if (previous[destination] == -1)
    return -1;
  return distance[destination];
}

int main() {
  int n, e;
  std::cin >> n >> e;
  while (n != 0 || e != 0) {
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, -1));

    while (e-- > 0) {
      int x, y, h;
      std::cin >> x >> y >> h;
      --x, --y;
      graph[x][y] = h;
      if (graph[y][x] != -1) {
        graph[x][y] = 0;
        graph[y][x] = 0;
      }
    }

    int k;
    std::cin >> k;
    while (k-- > 0) {
      int o, d;
      std::cin >> o >> d;
      int distance = dijkstra(graph, --o, --d);
      if (distance == -1)
        std::cout << "Nao e possivel entregar a carta";
      else
        std::cout << distance;
      std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cin >> n >> e;
  }
  return 0;
}
