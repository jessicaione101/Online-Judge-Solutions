// https://www.urionlinejudge.com.br/judge/en/problems/view/2356

#include <iostream>
#include <string>

int main() {
  std::string d, s;
  while (std::cin >> d >> s) {
    bool resistant = false;
    for (size_t i = 0; i < d.size() && !resistant; ++i) {
      if (d[i] == s[0])
        resistant = s.compare(d.substr(i, s.size())) == 0;
    }
    if (resistant)
      std::cout << "Resistente";
    else
      std::cout << "Nao resistente";
    std::cout << std::endl;
  }
  return 0;
}
