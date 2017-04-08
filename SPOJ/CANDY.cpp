// http://www.spoj.com/problems/CANDY/

#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  while (n != -1) {
    std::vector<int> candies(n);
    int average = 0, c;
    for (int i = 0; i < n; ++i) {
      std::cin >> c;
      candies[i] = c;
      average += c;
    }

    if (average % n != 0) {
      std::cout << -1;
    } else {
      average /= n;
      int moves = 0;
      for (int i = 0; i < n; ++i) {
        if (candies[i] > average)
          moves += candies[i] - average;
      }
      std::cout << moves;
    }

    std::cout << std::endl;
    std::cin >> n;
  }
  return 0;
}
