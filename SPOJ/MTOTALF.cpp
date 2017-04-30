// http://www.spoj.com/problems/MTOTALF/

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

const int kMaxSize = 100;
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
  std::map<char, int> pipes;
  std::vector<std::vector<int>> flows(kMaxSize, std::vector<int>(kMaxSize));
  std::vector<std::vector<int>> graph;

  int n;
  std::cin >> n;
  while (n-- > 0) {
    char a, b;
    int f;
    std::cin >> a >> b >> f;

    if (pipes.find(a) == pipes.end()) {
      pipes[a] = pipes.size()-1;
      graph.push_back(std::vector<int>());
    }
    if (pipes.find(b) == pipes.end()) {
      pipes[b] = pipes.size()-1;
      graph.push_back(std::vector<int>());
    }

    flows[pipes[a]][pipes[b]] += f;
    flows[pipes[b]][pipes[a]] += f;
    graph[pipes[a]].push_back(pipes[b]);
    graph[pipes[b]].push_back(pipes[a]);
  }

  std::cout << maxFlow(pipes['A'], pipes['Z'], graph, &flows) << std::endl;

  return 0;
}
