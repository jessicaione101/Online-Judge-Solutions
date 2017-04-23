// http://br.spoj.com/problems/CONTAGEM/

#include <iostream>
#include <string>
#include <cmath>

int main() {
  int test = 0;
  std::string word;
  while (std::cin >> word) {
    int64_t cost = 0;
    for (size_t i = 0; i < word.size(); ++i) {
      if (word[i] == 'b')
        cost += (int64_t)pow(2, word.size() - i - 1);
    }
    std::cout << "Palavra " << ++test << std::endl;
    std::cout << cost << std::endl;
  }
  return 0;
}
