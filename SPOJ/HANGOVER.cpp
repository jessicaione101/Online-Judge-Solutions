// http://www.spoj.com/problems/HANGOVER/

#include <iostream>
#include <vector>
#include <algorithm>

const int kMax = 275;

int main() {
  std::vector<double> card_lengths(kMax);
  for (int i = 1; i < kMax; ++i)
    card_lengths[i] = card_lengths[i-1] + 1 / static_cast<double>(i+1);

  double c;
  std::cin >> c;
  while (c != 0) {
    std::vector<double>::iterator it;
    it = std::upper_bound(card_lengths.begin(), card_lengths.end(), c);
    std::cout << it - card_lengths.begin() << " card(s)" << std::endl;
    std::cin >> c;
  }

  return 0;
}
