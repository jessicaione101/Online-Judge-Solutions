// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1162

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

const double kPi = acos(-1);
const int kEarthRadius = 6440;

int main() {
  std::cout << std::fixed << std::setprecision(6);

  int s, a;
  std::string unit;
  while (std::cin >> s >> a >> unit) {
    s += kEarthRadius;

    double angle = a;
    if (unit.compare("min") == 0)
      angle /= 60;
    if (angle > 180)
      angle = 360 - angle;
    angle *= kPi / 180.0;

    double arc = s * angle;
    double chord = 2 * s * sin(angle / 2.0);

    std::cout << arc << " " << chord << std::endl;
  }

  return 0;
}
