// http://br.spoj.com/problems/ENCOTEL/

#include <iostream>
#include <string>
#include <map>

std::map<char, char> buildTable() {
  std::map<char, char> table;
  table['A'] = table['B'] = table['C'] = '2';
  table['D'] = table['E'] = table['F'] = '3';
  table['G'] = table['H'] = table['I'] = '4';
  table['J'] = table['K'] = table['L'] = '5';
  table['M'] = table['N'] = table['O'] = '6';
  table['P'] = table['Q'] = table['R'] = table['S'] = '7';
  table['T'] = table['U'] = table['V'] = '8';
  table['W'] = table['X'] = table['Y'] = table['Z'] = '9';
  table['0'] = '0';
  table['1'] = '1';
  table['-'] = '-';
  return table;
}

int main() {
  std::map<char, char> table = buildTable();
  std::string phone_number;
  while (std::cin >> phone_number) {
    for (size_t i = 0; i < phone_number.size(); ++i)
      std::cout << table[phone_number[i]];
    std::cout << std::endl;
  }
  return 0;
}
