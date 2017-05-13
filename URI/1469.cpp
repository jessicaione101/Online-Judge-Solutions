// https://www.urionlinejudge.com.br/judge/en/problems/view/1469

#include <iostream>
#include <vector>
#include <algorithm>

const int kMaxAge = 101;

int depthFirstSearch(const std::vector<std::vector<int>>& graph,
                     const std::vector<int>& age,
                     std::vector<bool>* visited,
                     const int employee,
                     int min_age) {
  for (size_t i = 0; i < graph[employee].size(); ++i) {
    int supervisor = graph[employee][i];
    if (!(*visited)[supervisor]) {
      (*visited)[supervisor] = true;
      if (age[supervisor] < min_age)
        min_age = age[supervisor];
      min_age = depthFirstSearch(graph, age, visited, supervisor, min_age);
    }
  }
  return min_age;
}

int main() {
  int n, m , i;
  while (std::cin >> n >> m >> i) {
    std::vector<int> age(n);
    std::vector<std::vector<int>> graph(n);

    for (int i = 0; i < n; ++i)
      std::cin >> age[i];

    int x, y;
    while (m-- > 0) {
      std::cin >> x >> y;
      --x, --y;
      graph[y].push_back(x);
    }

    char instruction;
    int a, b;
    while (i-- > 0) {
      std::cin >> instruction;
      if (instruction == 'P') {
        std::cin >> a;
        --a;
        std::vector<bool> visited(graph.size());
        int min_age = depthFirstSearch(graph, age, &visited, a, kMaxAge);
        if (min_age == kMaxAge)
          std::cout << "*";
        else
          std::cout << min_age;
        std::cout << std::endl;
      } else {
        std::cin >> a >> b;
        --a, --b;
        std::vector<int>::iterator it_a, it_b;
        for (size_t i = 0; i < graph.size(); ++i) {
          it_a = std::find(graph[i].begin(), graph[i].end(), a);
          it_b = std::find(graph[i].begin(), graph[i].end(), b);
          if (it_a != graph[i].end())
            *it_a = b;
          if (it_b != graph[i].end())
            *it_b = a;
        }
        std::vector<int> a_supervisor_list = graph[a];
        std::vector<int> b_supervisor_list = graph[b];
        graph[a] = b_supervisor_list;
        graph[b] = a_supervisor_list;
      }
    }
  }
  return 0;
}
