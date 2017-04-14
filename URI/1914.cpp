// https://www.urionlinejudge.com.br/judge/en/problems/view/1914

#include <iostream>
#include <string>
#include <utility>

int main() {
  int qt;
  std::cin >> qt;
  while (qt-- > 0) {
    std::pair<std::string, std::string> player1, player2;
    std::cin >> player1.first >> player1.second;
    std::cin >> player2.first >> player2.second;

    int m, score;
    std::cin >> m;
    std::cin >> score;
    score += m;

    std::string win_condition, winner;
    if (score % 2 == 0)
      win_condition = "PAR";
    else
      win_condition = "IMPAR";

    winner = player1.second.compare(win_condition) == 0 ?
      player1.first : player2.first;
    std::cout << winner << std::endl;
  }
  return 0;
}
