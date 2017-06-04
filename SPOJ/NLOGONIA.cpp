// http://br.spoj.com/problems/NLOGONIA/

#include <iostream>

const char* country(const int reference_x, const int reference_y,
              const int x, const int y) {
  if (x < reference_x && y > reference_y)
    return "NO";
  if (x > reference_x && y > reference_y)
    return "NE";
  if (x > reference_x && y < reference_y)
    return "SE";
  if (x < reference_x && y < reference_y)
    return "SO";
  return "divisa";
}

int main() {
  int k;
  std::cin >> k;
  while (k != 0) {
    int n, m;
    std::cin >> n >> m;
    int x, y;
    while (k-- > 0) {
      std::cin >> x >> y;
      std::cout << country(n, m, x, y) << std::endl;
    }
    std::cin >> k;
  }
  return 0;
}
