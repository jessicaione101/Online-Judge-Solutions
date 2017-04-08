// http://br.spoj.com/problems/BANDA09/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> musicians(n, std::vector<int>(n));

  int x, y, z;
  while (m-- > 0) {
    std::cin >> x >> y >> z;
    musicians[x-1][y-1] = z;
    musicians[y-1][x-1] = z;
  }

  std::string bitmask(3, 1);
  bitmask.resize(n, 0);
  int max_relation = 0;
  int max_x = 0, max_y = 1, max_z = 2;
  int index[3], j = 0;

  do {
    for (int i = 0; i < n; ++i) {
      if (bitmask[i])
        index[j++] = i;
    }

    x = index[0]; y = index[1]; z = index[2];
    int relation = musicians[x][y] + musicians[x][z] + musicians[y][z];

    if (relation > max_relation) {
      max_relation = relation;
      max_x = x; max_y = y; max_z = z;
    }

    j = 0;
  } while (std::prev_permutation(bitmask.begin(), bitmask.end()));

  std::cout << max_x+1 << " " << max_y+1 << " " << max_z+1 << std::endl;

  return 0;
}
