// http://br.spoj.com/problems/CAIXAS/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
  int n, p;
  std::cin >> n >> p;
  while (n != 0 || p != 0) {
    std::vector<std::vector<int>> stack(p);

    int q, b, box;
    for (int i = 0; i < p; ++i) {
      std::cin >> q;
      while (q-- > 0) {
      std::cin >> b;
        stack[i].push_back(b);
        if (b == 1) box = i;
      }
    }

    size_t height = std::distance(
      stack[box].begin(), std::find(stack[box].begin(), stack[box].end(), 1));
    ++height;

    int left = 0, right = 0;
    for (int i = box-1; i >= 0 && stack[i].size() >= height; --i)
      left += stack[i].size() - height + 1;
    for (size_t i = box+1; i < stack.size() && stack[i].size() >= height; ++i)
      right += stack[i].size() - height + 1;

    int output = stack[box].size() - height;
    output += left < right ? left : right;

    std::cout << output << std::endl;
    std::cin >> n >> p;
  }

  return 0;
}
