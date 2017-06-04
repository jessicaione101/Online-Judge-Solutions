// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2500

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

const double kPi = acos(-1.0);

void update(const std::string command, const int units,
            double* x, double* y, int* angle) {
  if (command.compare("lt") == 0) {
    *angle += units;
  } else if (command.compare("rt") == 0) {
    *angle -= units;
  } else if (command.compare("fd") == 0) {
    *x += units * cos(*angle * kPi / 180.0);
    *y += units * sin(*angle * kPi / 180.0);
  } else if (command.compare("bk") == 0) {
    *x -= units * cos(*angle * kPi / 180.0);
    *y -= units * sin(*angle * kPi / 180.0);
  }
}

int main() {
  int tests;
  std::cin >> tests;
  std::cout << std::fixed << std::setprecision(0);
  while (tests-- > 0) {
    int total_commands;
    std::cin >> total_commands;

    double x = 0, y = 0;
    int angle = 0, units;
    std::string command;
    while (total_commands-- > 0) {
      std::cin >> command >> units;
      update(command, units, &x, &y, &angle);
    }

    std::cout << hypot(x, y) << std::endl;
  }

  return 0;
}
