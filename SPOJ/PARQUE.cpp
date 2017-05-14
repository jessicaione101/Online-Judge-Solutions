// http://br.spoj.com/problems/PARQUE/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string backtrack(
    const std::vector<std::vector<int>>& lcs_length,
    const std::string& s1,
    const std::string& s2,
    const size_t s1_index,
    const size_t s2_index) {
  if (s1_index != 0 && s2_index != 0)
    if (s1[s1_index] == s2[s2_index])
      return
        backtrack(lcs_length, s1, s2, s1_index-1, s2_index-1) + s1[s1_index];

  if (s1_index > 0 &&
      lcs_length[s1_index][s2_index] == lcs_length[s1_index-1][s2_index] + 1)
    return backtrack(lcs_length, s1, s2, s1_index-1, s2_index) + s1[s1_index];

  if (s2_index > 0)
    return backtrack(lcs_length, s1, s2, s1_index, s2_index-1) + s2[s2_index];

  return "";
}

std::vector<std::vector<int>> lcsLength(const std::string& s1,
                                        const std::string& s2) {
  std::vector<std::vector<int>> length(s1.size(), std::vector<int>(s2.size()));
  for (size_t i = 1; i < s1.size(); ++i)
    length[i][0] = i;
  for (size_t i = 1; i < s2.size(); ++i)
    length[0][i] = i;

  for (size_t i = 1; i < s1.size(); ++i) {
    for (size_t j = 1; j < s2.size(); ++j) {
      if (s1[i] == s2[j])
        length[i][j] = length[i-1][j-1] + 1;
      else
        length[i][j] = std::min(length[i][j-1], length[i-1][j]) + 1;
    }
  }

  return length;
}

int main() {
  int test = 0;
  std::string s1, s2;
  std::cin >> s1 >> s2;
  while (s1.compare("#") != 0) {
    s1.insert(0, " ");
    s2.insert(0, " ");
    std::vector<std::vector<int>> lcs_length = lcsLength(s1, s2);
    std::cout << "Teste " << ++test << std::endl;
    std::cout << backtrack(lcs_length, s1, s2, s1.size(), s2.size());
    std::cout << std::endl << std::endl;
    std::cin >> s1 >> s2;
  }
  return 0;
}
