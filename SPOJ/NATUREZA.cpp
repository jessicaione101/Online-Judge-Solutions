// http://br.spoj.com/problems/NATUREZA/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>

int countFoodChain(const std::vector<std::vector<int>>& nature, int animal) {
  std::vector<bool> visited(nature.size());
  std::stack<int> to_visit;
  to_visit.push(animal);
  visited[animal] = true;
  int size = 1;
  while (!to_visit.empty()) {
    animal = to_visit.top();
    to_visit.pop();
    for (size_t i = 0; i < nature[animal].size(); ++i) {
      if (!visited[nature[animal][i]]) {
        visited[nature[animal][i]] = true;
        to_visit.push(nature[animal][i]);
        ++size;
      }
    }
  }
  return size;
}

int main() {
  int c, r;
  std::cin >> c >> r;
  while (c != 0 || r != 0) {
    std::map<std::string, int> animals;
    std::vector<std::vector<int>> nature(c);
    int value = 0;
    while (c-- > 0) {
      std::string animal;
      std::cin >> animal;
      animals[animal] = value++;
    }
    while (r-- > 0) {
      std::string prey, predator;
      std::cin >> prey >> predator;
      nature[animals[predator]].push_back(animals[prey]);
      nature[animals[prey]].push_back(animals[predator]);
    }

    int max = 0;
    for (size_t i = 0; i < nature.size(); ++i) {
      int size = countFoodChain(nature, i);
      if (size > max)
        max = size;
    }

    std::cout << max << std::endl;
    std::cin >> c >> r;
  }
  return 0;
}
