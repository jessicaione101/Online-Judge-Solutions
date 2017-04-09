// http://www.spoj.com/problems/CMIYC/

#include <iostream>

int main() {
  int n;
  std::cin >> n;
  while (n-- > 0) {
    int64_t size;
    std::cin >> size;
    int64_t distance = size%3 == 0 ? size/3 : 0;
    std::cout << distance << std::endl;
  }
  return 0;
}
