// https://www.urionlinejudge.com.br/judge/en/problems/view/1514

#include <iostream>
#include <vector>
#include <algorithm>

bool nobodySolvedAllProblems(
    const std::vector<std::vector<bool>>& competition) {
  for (size_t i = 0; i < competition.size(); ++i)
    if (std::find(competition[i].begin(), competition[i].end(), false) ==
        competition[i].end())
      return false;
  return true;
}

bool allProblemsSolved(const std::vector<std::vector<bool>>& competition) {
  size_t cols = competition[0].size();

  bool solved = false;
  for (size_t j = 0; j < cols; ++j) {
    for (size_t i = 0; i < competition.size(); ++i) {
      if (competition[i][j]) {
        solved = true;
        break;
      }
    }
    if (!solved)
      return false;
    solved = false;
  }

  return true;
}

bool noProblemSolvedByEverybody(
    const std::vector<std::vector<bool>>& competition) {
  size_t cols = competition[0].size();

  bool unsolved = false;
  for (size_t j = 0; j < cols; ++j) {
    for (size_t i = 0; i < competition.size(); ++i) {
      if (!competition[i][j]) {
        unsolved = true;
        break;
      }
    }
    if (!unsolved)
      return false;
    unsolved = false;
  }

  return true;
}

bool everybodySolvedOneProblem(
    const std::vector<std::vector<bool>>& competition) {
  for (size_t i = 0; i < competition.size(); ++i)
    if (std::find(competition[i].begin(), competition[i].end(), true) ==
        competition[i].end())
      return false;
  return true;
}

int main() {
  int n, m;
  std::cin >> n >> m;

  while (n != 0 || m != 0) {
    std::vector<std::vector<bool>> competition(n, std::vector<bool>(m));

    bool answer;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        std::cin >> answer;
        competition[i][j] = answer;
      }
    }

    std::vector<bool> features(4);
    features[0] = nobodySolvedAllProblems(competition);
    features[1] = allProblemsSolved(competition);
    features[2] = noProblemSolvedByEverybody(competition);
    features[3] = everybodySolvedOneProblem(competition);

    std::cout <<
      std::count(features.begin(), features.end(), true) << std::endl;

    std::cin >> n >> m;
  }

  return 0;
}
