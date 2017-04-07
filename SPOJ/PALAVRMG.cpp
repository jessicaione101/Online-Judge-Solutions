// http://br.spoj.com/problems/PALAVRMG/

#include <iostream>
#include <string>
#include <algorithm>

int main() {
  std::string word_original;
  int n;
  std::cin >> n;
  while (n-- > 0) {
    std::cin >> word_original;
    std::string word_lowercase(word_original);
    std::transform(word_lowercase.begin(), word_lowercase.end(),
      word_lowercase.begin(), ::tolower);

    size_t size = word_lowercase.size();
    char output = 'O';
    for (size_t i = 0; i < size-1; ++i) {
      if (word_lowercase[i] >= word_lowercase[i+1]) {
        output = 'N';
        break;
      }
    }
    std::cout << word_original << ": " << output << std::endl;
  }

  return 0;
}
