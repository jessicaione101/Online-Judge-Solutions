// http://br.spoj.com/problems/WCW/

#include <iostream>
#include <vector>

int main() {
  int t;
  std::cin >> t;
  while (t-- > 0) {
    int n;
    std::cin >> n;
    std::vector<int> sequence(n);

    for (int i = 0; i < n; ++i)
      std::cin >> sequence[i];

    int temp, swap = 0;
    for (int i = 0; i < n; ++i) {
      while (sequence[i] != i+1) {
        temp = sequence[i];
        sequence[i] = sequence[temp-1];
        sequence[temp-1] = temp;
        ++swap;
      }
    }

    std::cout << swap << std::endl;
  }

  return 0;
}
