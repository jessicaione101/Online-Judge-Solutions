// http://br.spoj.com/problems/MARAT09/

#include <iostream>

int main() {
  int n, m, previous, next;
  bool can_finish = true;
  std::cin >> n >> m;
  std::cin >> previous;
  while (--n > 0) {
    std::cin >> next;
    if (can_finish && next - previous > m)
      can_finish = false;
    previous = next;
  }
  if (can_finish && 42195 - previous > m)
      can_finish = false;

  if (can_finish)
    std::cout << "S";
  else
    std::cout << "N";
  std::cout << std::endl;

  return 0;
}
