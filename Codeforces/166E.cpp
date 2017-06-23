// http://codeforces.com/problemset/problem/166/E

#include <iostream>

const int kMod = 1000000007;

int main() {
  int64_t n;
  std::cin >> n;
  int64_t paths = 0;

  if (n >= 2)
    paths = 3;

  if (n > 2) {
    bool sum = false;
    while (n-- > 2) {
      if (sum) {
        paths = ((paths % kMod) * (3 % kMod) % kMod + 3) % kMod;
        sum = !sum;
      } else {
        paths = ((paths % kMod) * (3 % kMod) % kMod - 3) % kMod;
        sum = !sum;
      }
    }
  }

  std::cout << paths % kMod << std::endl;

  return 0;
}
