// https://www.urionlinejudge.com.br/judge/en/problems/view/1260

#include <iostream>
#include <map>
#include <string>
#include <numeric>
#include <utility>
#include <iomanip>

int main() {
  int n;
  std::cin >> n;
  std::string tree;
  std::map<std::string, int> trees;

  std::getline(std::cin, tree);
  if (n > 0)
    std::getline(std::cin, tree);

  while (n > 0) {
    std::getline(std::cin, tree);
    while (!tree.empty() && !std::cin.eof()) {
      ++trees[tree];
      std::getline(std::cin, tree);
    }

    double total = std::accumulate(trees.begin(), trees.end(), 0,
      [](int sum, const std::pair<std::string, int>& p) -> int {
        return sum + p.second;
      });

    std::map<std::string, int>::iterator it;
    for (it = trees.begin(); it != trees.end(); ++it) {
      std::cout << it->first << " ";
      std::cout << std::fixed << std::setprecision(4);
      std::cout << it->second / total * 100 << std::endl;
    }
    if (n-1 > 0)
      std::cout << std::endl;

    trees.clear();
    --n;
  }

  return 0;
}
