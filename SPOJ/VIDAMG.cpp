// http://br.spoj.com/problems/VIDAMG/

#include <iostream>
#include <set>
#include <utility>
#include <vector>

const std::vector<std::pair<int, int>> kAdjacent{
  {1, 0}, {0, 1}, {1, 1}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};

int countAdjacentCells(const std::set<std::pair<int, int>>& board,
               const int x, const int y) {
  int alive = 0;
  std::set<std::pair<int, int>>::const_iterator cell;
  for (size_t i = 0; i < kAdjacent.size(); ++i) {
    cell =
      board.find(std::make_pair(x+kAdjacent[i].first, y+kAdjacent[i].second));
    if (cell != board.end())
      ++alive;
  }
  return alive;
}

std::set<std::pair<int, int>> play(std::set<std::pair<int, int>> board,
                                   int iterations) {
  std::set<std::pair<int, int>> playing_board;
  int x, y, alive_neighbors;
  std::set<std::pair<int, int>>::iterator it;
  while (iterations-- > 0) {
    playing_board = board;

    for (it = board.begin(); it != board.end(); ++it) {
      alive_neighbors = countAdjacentCells(board, it->first, it->second);
      if (alive_neighbors < 2 || alive_neighbors > 3)
        playing_board.erase(std::make_pair(it->first, it->second));

      for (size_t i = 0; i < kAdjacent.size(); ++i) {
        x = it->first + kAdjacent[i].first;
        y = it->second + kAdjacent[i].second;
        alive_neighbors = countAdjacentCells(board, x, y);
        if (alive_neighbors == 3)
          playing_board.insert(std::make_pair(x, y));
      }
    }

    board = playing_board;
  }

  return board;
}

int main() {
  int n;
  std::cin >> n;
  while (n != 0) {
    std::set<std::pair<int, int>> board;
    int l, c;
    while (n-- > 0) {
      std::cin >> l >> c;
      board.insert(std::make_pair(l, c));
    }

    int k;
    std::cin >> k;
    std::set<std::pair<int, int>> end_board = play(board, k);

    std::cout << end_board.size() << std::endl;
    std::set<std::pair<int, int>>::iterator it;
    for (it = end_board.begin(); it != end_board.end(); ++it)
      std::cout << it->first << " " << it->second << std::endl;

    std::cin >> n;
  }

  return 0;
}
