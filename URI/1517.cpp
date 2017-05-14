// https://www.urionlinejudge.com.br/judge/en/problems/view/1517

#include <iostream>
#include <cstring>
#include <algorithm>

const int kMaxSize = 21;
const int kMaxTime = 2001;
bool space_time[kMaxSize][kMaxSize][kMaxTime];
int total_apples[kMaxSize][kMaxSize][kMaxTime];
int max_row, max_col, max_time;

int maxApples(const int row, const int col, const int time) {
  if (row <= 0 || row > max_row ||
      col <= 0 || col > max_col ||
      time > max_time)
    return 0;

  if (total_apples[row][col][time] != -1)
    return total_apples[row][col][time];

  int apples = 0;
  apples = std::max(apples, maxApples(row, col, time+1));
  apples = std::max(apples, maxApples(row+1, col, time+1));
  apples = std::max(apples, maxApples(row-1, col, time+1));
  apples = std::max(apples, maxApples(row, col+1, time+1));
  apples = std::max(apples, maxApples(row, col-1, time+1));
  apples = std::max(apples, maxApples(row+1, col+1, time+1));
  apples = std::max(apples, maxApples(row-1, col-1, time+1));
  apples = std::max(apples, maxApples(row+1, col-1, time+1));
  apples = std::max(apples, maxApples(row-1, col+1, time+1));

  apples += space_time[row][col][time] ? 1 : 0;
  return (total_apples[row][col][time] = apples);
}

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;
  while (n != 0 || m != 0 || k != 0) {
    memset(space_time, 0, sizeof(bool)*kMaxSize*kMaxSize*kMaxTime);
    memset(total_apples, -1, sizeof(total_apples));
    int x, y, t;
    while (k-- > 0) {
      std::cin >> x >> y >> t;
      space_time[x][y][t] = true;
    }
    std::cin >> x >> y;
    max_row = n, max_col = m, max_time = t;
    std::cout << maxApples(x, y, 0) << std::endl;
    std::cin >> n >> m >> k;
  }

  return 0;
}
