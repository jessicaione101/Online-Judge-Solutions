// https://www.urionlinejudge.com.br/judge/en/problems/view/1559

#include <iostream>
#include <vector>
#include <string>

const int kSize = 4;

bool checkBlock(const std::vector<std::vector<int>>& board,
                const int row, const int col, const int value) {
  int size = board.size();
  return row >= 0 && row < size && col >= 0 && col < size &&
    (board[row][col] == 0 || board[row][col] == value);
}

int main() {
  int tests;
  std::cin >> tests;
  while (tests-- > 0) {
    std::vector<std::vector<int>> board(kSize, std::vector<int>(kSize));

    int n;
    for (int i = 0; i < kSize; ++i) {
      for (int j = 0; j < kSize; ++j) {
        std::cin >> n;
        board[i][j] = n;
      }
    }

    bool down = false, left = false, right = false, up = false, stop = false;
    for (int i = 0; i < kSize && !stop; ++i) {
      for (int j = 0; j < kSize && !stop; ++j) {
        if (board[i][j] == 2048) {
          down = false;
          left = false;
          right = false;
          up = false;
          stop = true;
        } else if (board[i][j] != 0) {
          bool block_down = checkBlock(board, i+1, j, board[i][j]);
          bool block_left = checkBlock(board, i, j-1, board[i][j]);
          bool block_right = checkBlock(board, i, j+1, board[i][j]);
          bool block_up = checkBlock(board, i-1, j, board[i][j]);

          down = down || block_down;
          left = left || block_left;
          right = right || block_right;
          up = up || block_up;
        }
      }
    }

    std::string output;
    if (down) output += "DOWN ";
    if (left) output += "LEFT ";
    if (right) output += "RIGHT ";
    if (up) output += "UP ";
    if (output.empty())
      output = "NONE";
    else
      output.pop_back();
    std::cout << output << std::endl;
  }
  return 0;
}
