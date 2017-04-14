// https://www.urionlinejudge.com.br/judge/en/problems/view/2091

#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

bool isLonely(const std::pair<int64_t, int>& p) {
  return p.second % 2 == 1;
}

int main() {
  int n;
  std::cin >> n;
  while (n != 0) {
    std::map<int64_t, int> numbers;
    while (n-- > 0) {
      int64_t number;
      std::cin >> number;
      ++numbers[number];
    }

  std::cout <<
    (*std::find_if(numbers.begin(), numbers.end(), isLonely)).first <<
    std::endl;

    std::cin >> n;
  }
  return 0;
}
