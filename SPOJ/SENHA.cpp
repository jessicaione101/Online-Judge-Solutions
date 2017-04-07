// http://br.spoj.com/problems/SENHA/

#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

int main() {
  std::map<char, std::pair<int, int>> letters;
  int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  int n, test = 0;
  char c;
  std::cin >> n;
  while (n != 0) {
    std::vector<std::set<int>> password(6, std::set<int>(digits, digits+10));

    while (n-- > 0) {
      for (c = 'A'; c <= 'E'; ++c)
        std::cin >> letters[c].first >> letters[c].second;

      for (int i = 0; i < 6; ++i) {
        std::cin >> c;
        for (int j = 0; j < 10; ++j) {
          if (digits[j] != letters[c].first && digits[j] != letters[c].second)
            password[i].erase(digits[j]);
        }
      }
    }

    std::cout << "Teste " << ++test << std::endl;
    for (int i = 0; i < 6; ++i) {
      std::cout << *(password[i].begin()) << " ";
    }
    std::cout << std::endl << std::endl;

    std::cin >> n;
  }

  return 0;
}
