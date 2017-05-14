// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=293

#include <iostream>
#include <vector>

const int kMax = 30001;

int main() {
  std::vector<int> coins{1, 5, 10, 25, 50};
  std::vector<int64_t> count(kMax);
  count[0] = 1;

  for (size_t i = 0; i < coins.size(); ++i)
    for (int j = coins[i]; j < kMax; ++j)
      count[j] += count[j - coins[i]];

  int n;
  while (std::cin >> n) {
    if (count[n] > 1)
      std::cout << "There are " << count[n] << " ways to produce "
        << n << " cents change." << std::endl;
    else
      std::cout << "There is only 1 way to produce "
        << n << " cents change." << std::endl;
  }

  return 0;
}
