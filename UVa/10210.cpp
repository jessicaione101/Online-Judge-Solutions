// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1151

#include <iostream>
#include <cmath>
#include <iomanip>

const double kPi = acos(-1.0);

int main() {
  std::cout << std::fixed << std::setprecision(3);
  double x1, y1, x2, y2, cmd, enf;
  while (std::cin >> x1 >> y1 >> x2 >> y2 >> cmd >> enf) {
    std::cout << hypot(x1-x2, y1-y2) *
      (1 / tan(cmd * kPi / 180.0) + 1 / tan(enf * kPi / 180.0))
      << std::endl;
  }
  return 0;
}
