// https://www.urionlinejudge.com.br/judge/en/problems/view/1905

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

const int kSize = 5;

bool solve(const std::vector<std::vector<bool>>& maze,
           std::vector<std::vector<bool>>* visited,
           const int row, const int col) {
  if (row < 0 || col < 0 || row >= kSize || col >= kSize)
    return false;

  if ((*visited)[row][col] || maze[row][col])
    return false;

  if (row == kSize-1 && col == kSize-1 && !maze[row][col])
    return true;

  (*visited)[row][col] = true;

  return solve(maze, visited, row+1, col) ||
    solve(maze, visited, row, col+1) ||
    solve(maze, visited, row-1, col) ||
    solve(maze, visited, row, col-1);
}

int main() {
  int t;
  std::cin >> t;
  while (t-- > 0) {
    std::vector<std::vector<bool>> maze(kSize, std::vector<bool>(kSize));
    std::string line;
    for (int i = 0; i < kSize; ++i) {
      while (std::getline(std::cin, line) && line.size() <= 1) continue;
      std::istringstream input(line);
      int m;
      for (int j = 0; j < kSize; ++j) {
        input >> m;
        maze[i][j] = m;
      }
    }

    std::vector<std::vector<bool>> visited(kSize, std::vector<bool>(kSize));
    if (solve(maze, &visited, 0, 0))
      std::cout << "COPS";
    else
      std::cout << "ROBBERS";
    std::cout << std::endl;
  }
  return 0;
}
