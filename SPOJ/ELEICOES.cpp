// http://br.spoj.com/problems/ELEICOES/

#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::map<int, int> candidates;

  int i;
  for (int j = 0; j < n; ++j) {
    std::cin >> i;
    ++candidates[i];
  }

  std::cout << (std::max_element(candidates.begin(), candidates.end(),
    [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) -> bool {
      return p1.second < p2.second;
    }))->first << std::endl;

  return 0;
}
