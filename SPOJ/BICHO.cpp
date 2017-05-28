// http://br.spoj.com/problems/BICHO/

#include <iostream>
#include <iomanip>

int main() {
  int animal_group[100];
  animal_group[0] = 24;
  for (int i = 1; i < 100; i++)
    animal_group[i] = (i - 1) / 4;
  double v;
  int n, m;
  std::cin >> v >> n >> m;
  std::cout << std::fixed << std::setprecision(2);
  while (v != 0 || n != 0 || m != 0) {
    double prize = 0;
    if (n % 10000 == m % 10000)
      prize = v * 3000;
    else if (n % 1000 == m % 1000)
      prize = v * 500;
    else if (n % 100 == m % 100)
      prize = v * 50;
    else if (animal_group[n%100] == animal_group[m%100])
      prize = v * 16;
    std::cout << prize << std::endl;
    std::cin >> v >> n >> m;
  }
  return 0;
}
