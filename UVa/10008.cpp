// https://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&problem=949

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

bool compare(const std::pair<char, int>& left,
             const std::pair<char, int>& right) {
  return left.second == right.second ?
    left.first < right.first : left.second > right.second;
}

int main() {
  std::map<char, int> counter;
  int n;
  std::cin >> n;
  std::string line;
  std::getline(std::cin, line);
  while (n-- > 0) {
    std::getline(std::cin, line);
    char c;
    for (size_t i = 0; i < line.size(); ++i) {
      c = toupper(line[i]);
      if (c >= 'A' && c <= 'Z')
        ++counter[c];
    }
  }

  std::vector<std::pair<char, int>>
    counter_ordered(counter.begin(), counter.end());
  std::sort(counter_ordered.begin(), counter_ordered.end(), compare);
  for (size_t i = 0; i < counter_ordered.size(); ++i)
    std::cout << counter_ordered[i].first << " "
      << counter_ordered[i].second << std::endl;

  return 0;
}
