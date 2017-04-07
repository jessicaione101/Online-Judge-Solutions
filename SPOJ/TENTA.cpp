// http://br.spoj.com/problems/TENTA/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> stamps;

  int n;
  std::cin >> n;
  while (n != 0) {
    int stamp_number;
    while (n-- > 0) {
      std::cin >> stamp_number;
      stamps.push_back(stamp_number);
    }

    std::sort(stamps.begin(), stamps.end());
    do {
      size_t size = stamps.size();
      for (size_t i = 0; i < size; ++i)
        std::cout << stamps[i] << " ";
      std::cout << std::endl;
    } while (std::next_permutation(stamps.begin(), stamps.end()));
    std::cout << std::endl;

    stamps.clear();
    std::cin >> n;
  }

  return 0;
}
