// http://br.spoj.com/problems/ELEVADOR/

#include <iostream>

int main() {
  int l, c, r1, r2;
  std::cin >> l >> c >> r1 >> r2;
  while (l != 0 || c != 0 || r1 != 0 || r2 != 0) {
    char answer = 'N';
    if (r1*2 <= l && r1*2 <= c && r2*2 <= l && r2*2 <= c) {
      double max_distance = (l-r1-r2)*(l-r1-r2) + (c-r1-r2)*(c-r1-r2);
        if (max_distance >= (r1+r2)*(r1+r2))
          answer = 'S';
    }
    std::cout << answer << std::endl;
    std::cin >> l >> c >> r1 >> r2;
  }
  return 0;
}
