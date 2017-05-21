// http://codeforces.com/problemset/problem/50/B

#include <iostream>
#include <string>
#include <map>

int main() {
  std::string s;
  std::cin >> s;

  std::map<char, int64_t> counter;
  for (size_t i = 0; i < s.size(); ++i)
    ++counter[s[i]];

  int64_t total = 0;
  std::map<char, int64_t>::iterator it;
  for (it = counter.begin(); it != counter.end(); ++it)
    total += it->second * it->second;

  std::cout << total << std::endl;

  return 0;
}
