// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2380

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

std::map<int, int> buildCipher() {
  std::vector<int> fibonacci(44);
  fibonacci[0] = 1;
  fibonacci[1] = 2;
  for (size_t i = 2; i < fibonacci.size(); ++i)
    fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];

  std::map<int, int> cipher;
  for (size_t i = 0; i < fibonacci.size(); ++i)
    cipher[fibonacci[i]] = i;

  return cipher;
}

int main() {
  std::map<int, int> cipher = buildCipher();
  int t;
  std::cin >> t;
  while (t-- > 0) {
    int n;
    std::cin >> n;
    std::vector<int> key(n);
    for (int i = 0; i < n; ++i)
      std::cin >> key[i];
    std::string line;
    std::getline(std::cin, line);
    std::getline(std::cin, line);

    int size = cipher[*std::max_element(key.begin(), key.end())];
    std::string message(size+1, ' ');
    int position;
    for (size_t i = 0, j = 0; i < line.size() && j < key.size(); ++i) {
      if (line[i] >= 'A' && line[i] <= 'Z') {
        position = cipher[key[j]];
        message[position] = line[i];
        ++j;
      }
    }

    size_t trim = message.find_last_not_of(" ");
    if (trim != std::string::npos)
      message.erase(trim+1);
    std::cout << message << std::endl;
  }

  return 0;
}

