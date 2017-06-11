// http://www.spoj.com/problems/LINESEG/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const char* parallelIntersection(const int c1a, const int c2a,
                                 const int c1b, const int c2b) {
  std::vector<std::pair<int, int>> lines(2);
  lines[0] = std::make_pair(std::min(c1a, c2a), std::max(c1a, c2a));
  lines[1] = std::make_pair(std::min(c1b, c2b), std::max(c1b, c2b));
  std::sort(lines.begin(), lines.end());

  int min1 = lines[0].first, min2 = lines[1].first, min3 = lines[0].second;
  if (min2 == min3)
    return "POINT";
  if (min2 >= min1 && min2 <= min3) {
    if (lines[0].first == lines[0].second || lines[1].first == lines[1].second)
      return "POINT";
    return "SEGMENT";
  }
  return "NO";
}

const char* perpendicularIntersection(const int x1v, const int y1v,
                                      const int x2v, const int y2v,
                                      const int x1h, const int y1h,
                                      const int x2h, const int y2h) {
  if (x1v >= std::min(x1h, x2h) && x1v <= std::max(x1h, x2h) &&
      std::min(y1v, y2v) <= y1h && std::max(y1v, y2v) >= y1h)
    return "POINT";
  return "NO";
}

const char* intersection(const char direction_a, const char direction_b,
                         const int x1a, const int y1a,
                         const int x2a, const int y2a,
                         const int x1b, const int y1b,
                         const int x2b, const int y2b) {
  if (direction_a == 'h' && direction_b == 'h') {
    if (y1a == y1b)
      return parallelIntersection(x1a, x2a, x1b, x2b);
  } else if (direction_a == 'v' && direction_b == 'v') {
    if (x1a == x1b)
      return parallelIntersection(y1a, y2a, y1b, y2b);
  } else if (direction_a == 'v' && direction_b == 'h') {
    return perpendicularIntersection(x1a, y1a, x2a, y2a, x1b, y1b, x2b, y2b);
  } else if (direction_a == 'h' && direction_b == 'v') {
    return perpendicularIntersection(x1b, y1b, x2b, y2b, x1a, y1a, x2a, y2a);
  }
  return "NO";
}

int main() {
  int t;
  std::cin >> t;
  while (t-- > 0) {
    int x1a, y1a, x2a, y2a, x1b, y1b, x2b, y2b;
    std::cin >> x1a >> y1a >> x2a >> y2a;
    std::cin >> x1b >> y1b >> x2b >> y2b;
    char direction_a = x1a == x2a ? 'v' : 'h';
    char direction_b = x1b == x2b ? 'v' : 'h';

    std::cout <<
      intersection(direction_a, direction_b,
        x1a, y1a, x2a, y2a, x1b, y1b, x2b, y2b)
      << std::endl;
  }

  return 0;
}
