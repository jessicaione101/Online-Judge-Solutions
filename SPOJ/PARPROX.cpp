// http://br.spoj.com/problems/PARPROX/

#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <limits>
#include <iomanip>

int main() {
  int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> points(n);
  for (int i = 0; i < n; ++i)
    std::cin >> points[i].first >> points[i].second;

  double min_distance = std::numeric_limits<double>::max();

  if (n <= 1) {
    min_distance = 0;
  } else {
    double distance;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i != j) {
          distance = hypot(points[i].first - points[j].first,
            points[i].second - points[j].second);
          if (distance < min_distance)
            min_distance = distance;
        }
      }
    }
  }

  std::cout << std::fixed << std::setprecision(3);
  std::cout << min_distance << std::endl;

  return 0;
}
