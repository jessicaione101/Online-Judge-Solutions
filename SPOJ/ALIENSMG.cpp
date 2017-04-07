// http://br.spoj.com/problems/ALIENSMG/

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

int main() {
  int n;
  std::string s;
  std::set<std::string> dna;

  std::cin >> n;
  while (n != 0) {
    for (int i = 0; i < n; ++i) {
      std::cin >> s;
      std::sort(s.begin(), s.end());
      dna.insert(s);
    }
    std::cout << dna.size() << std::endl;
    dna.clear();
    std::cin >> n;
  }

  return 0;
}
