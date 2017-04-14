// https://www.urionlinejudge.com.br/judge/en/problems/view/1244

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>

bool sortByLength(const std::string& str1, const std::string& str2) {
  return str1.size() > str2.size();
}

int main() {
  int n;
  std::cin >> n;
  std::cin.ignore();
  while (n-- > 0) {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream input(line);
    std::vector<std::string> words{std::istream_iterator<std::string>{input},
      std::istream_iterator<std::string>{}};

    std::stable_sort(words.begin(), words.end(), sortByLength);

    size_t i;
    for (i = 0; i < words.size()-1; ++i)
      std::cout << words[i] << " ";
    std::cout << words[i] << std::endl;
  }
  return 0;
}
