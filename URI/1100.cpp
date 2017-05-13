// https://www.urionlinejudge.com.br/judge/en/problems/view/1100

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <functional>

const int kSize = 8;
const int kMax = 10000000;

int dijkstra(const std::vector<std::vector<int>>& graph,
             const int source, const int destination) {
  std::vector<int> distance(graph.size(), kMax);
  distance[source] = 0;
  std::vector<bool> visited(graph.size());
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
    std::greater<std::pair<int, int>>> to_visit;
  to_visit.push(std::make_pair(distance[source], source));

  while (!to_visit.empty()) {
    int visiting = to_visit.top().second;
    to_visit.pop();

    if (!visited[visiting]) {
      visited[visiting] = true;
      for (size_t i = 0; i < graph[visiting].size(); ++i) {
        int vertex = graph[visiting][i];
        if (distance[vertex] > distance[visiting] + 1) {
          distance[vertex] = distance[visiting] + 1;
          to_visit.push(std::make_pair(distance[vertex], vertex));
        }
      }
    }
  }

  return distance[destination];
}

void tryAdd(const std::vector<std::vector<int>>& vertices,
            std::vector<int>* graph, const int i, const int j, const int size) {
  if (i >= 0 && j >= 0 && i < size && j < size)
    (*graph).push_back(vertices[i][j]);
}

std::vector<std::vector<int>> buildGraph() {
  std::vector<std::vector<int>> vertices(kSize, std::vector<int>(kSize));
  int index = 0;
  for (size_t i = 0; i < vertices.size(); ++i)
    for (size_t j = 0; j < vertices.size(); ++j)
      vertices[i][j] = index++;

  std::vector<std::vector<int>> graph(index);
  int size = vertices.size();
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      tryAdd(vertices, &graph[vertices[i][j]], i-2, j-1, size);
      tryAdd(vertices, &graph[vertices[i][j]], i-2, j+1, size);
      tryAdd(vertices, &graph[vertices[i][j]], i-1, j-2, size);
      tryAdd(vertices, &graph[vertices[i][j]], i-1, j+2, size);
      tryAdd(vertices, &graph[vertices[i][j]], i+1, j-2, size);
      tryAdd(vertices, &graph[vertices[i][j]], i+1, j+2, size);
      tryAdd(vertices, &graph[vertices[i][j]], i+2, j-1, size);
      tryAdd(vertices, &graph[vertices[i][j]], i+2, j+1, size);
    }
  }

  return graph;
}

int main() {
  std::vector<std::vector<int>> graph = buildGraph();
  std::string from, to;
  while (std::cin >> from >> to) {
    int source = (from[0]-'a')*8 + from[1]-'0' - 1;
    int destination = (to[0]-'a')*8 + to[1]-'0' - 1;
    std::cout << "To get from " << from << " to " << to << " takes "
      << dijkstra(graph, source, destination) << " knight moves." << std::endl;
  }
  return 0;
}
