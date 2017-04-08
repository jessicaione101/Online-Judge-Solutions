// http://br.spoj.com/problems/POPULAR/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  while (n != 0) {
    std::vector<int> votes(n);
    int vote;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cin >> vote;
        votes[j] += vote;
      }
    }

    std::cout << *std::max_element(votes.begin(), votes.end()) << std::endl;
    std::cin >> n;
  }
  return 0;
}
