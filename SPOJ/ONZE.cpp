// http://br.spoj.com/problems/ONZE/

#include <iostream>
#include <string>

int main() {
  std::string input;
  std::cin >> input;
  while (input.compare("0") != 0) {
    int n, evens = 0, odds = 0;

    for (size_t i = 0; i < input.size(); ++i) {
      n = input[i] - '0';
      if ((i+1) % 2 == 0)
        evens += n;
      else
        odds += n;
    }

    std::cout << input;
    if (evens % 11 == odds % 11)
      std::cout << " is a multiple of 11.";
    else
      std::cout << " is not a multiple of 11.";
    std::cout << std::endl;

    std::cin >> input;
  }

  return 0;
}
