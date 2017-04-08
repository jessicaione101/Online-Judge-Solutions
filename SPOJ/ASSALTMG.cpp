// http://br.spoj.com/problems/ASSALTMG/

#include <iostream>
#include <vector>
#include <bitset>
#include <set>
#include <algorithm>
#include <cmath>

int main() {
  std::vector<std::bitset<32>> directors;

  int t;
  std::cin >> t;
  while (t-- > 0) {
    int m, d;
    std::cin >> m >> d;
    directors.resize(d);
    while (d-- > 0) {
      int c;
      std::cin >> c;
      while (c-- > 0) {
        int key;
        std::cin >> key;
        directors[d].set(key);
      }
    }

    d = directors.size();
    unsigned int bits = pow(2, d) - 1;
    unsigned int mask = 0;
    int min_hostages = 21;

    while (mask != (bits+1u)) {
      unsigned int mask_copy = mask;
      int group_size = 0;
      std::bitset<32> key_combination;

      for (int i = d-1; i >= 0; --i) {
        if ((mask_copy >> i) & 1) {
          key_combination |= directors[i];
          ++group_size;
        }
      }

      int group_keys = key_combination.count();
      if (group_keys >= m && group_size < min_hostages)
        min_hostages = group_size;

      mask += 1u;
    }

    if (min_hostages > 20)
      std::cout << "Desastre!";
    else
      std::cout << min_hostages;
    std::cout << std::endl;

    directors.clear();
  }

  return 0;
}
