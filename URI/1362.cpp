// https://www.urionlinejudge.com.br/judge/en/problems/view/1362

#include <iostream>
#include <vector>
#include <string>
#include <map>

bool depthFirstSearch(const int source, const int sink,
                      const std::vector<std::vector<int>>& capacity,
                      std::vector<std::vector<int>>* flow,
                      std::vector<bool>* visited) {
  if (source == sink)
    return true;
  for (size_t i = 0; i < capacity.size(); ++i) {
    if (!(*visited)[i] && capacity[source][i] - (*flow)[source][i] > 0) {
      (*visited)[source] = true;
      if (depthFirstSearch(i, sink, capacity, flow, visited)) {
        ++(*flow)[source][i];
        --(*flow)[i][source];
        return true;
      }
      (*visited)[source] = false;
    }
  }
  return false;
}

int maxMatching(const int source, const int sink,
                const std::vector<std::vector<int>>& capacity) {
  int matching = 0;
  std::vector<std::vector<int>>
    flow(capacity.size(), std::vector<int>(capacity.size()));
  std::vector<bool> visited(capacity.size());
  while (depthFirstSearch(source, sink, capacity, &flow, &visited)) {
    ++matching;
    visited.clear();
    visited.resize(capacity.size());
  }
  return matching;
}

int main() {
  std::map<std::string, int> index =
    {{"XXL", 1}, {"XL", 2}, {"L", 3}, {"M", 4}, {"S", 5}, {"XS", 6}};
  int tests;
  std::cin >> tests;
  while (tests-- > 0) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> capacity(m+8, std::vector<int>(m+8));

    int quantity = n / 6;
    for (int i = 1; i <= 6; ++i)
      capacity[m+i][m+7] = quantity;

    std::string size;
    for (int i = 1; i <= m; ++i) {
      std::cin >> size;
      capacity[i][m+index[size]] = 1;
      std::cin >> size;
      capacity[i][m+index[size]] = 1;
    }

    for (int i = 1; i <= m; ++i) {
      capacity[0][i] = 1;
    }

    int max_matching = maxMatching(0, m+7, capacity);
    if (max_matching >= m)
      std::cout << "YES";
    else
      std::cout << "NO";
    std::cout << std::endl;
  }
  return 0;
}
