// https://www.urionlinejudge.com.br/judge/en/problems/view/1022

#include <iostream>
#include <cassert>

int gcd(int a, int b) {
  int temp;
  while (b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main() {
  int n;
  std::cin >> n;
  while (n-- > 0) {
    int n1, d1, n2, d2;
    char c, operation;
    std::cin >> n1;
    std::cin >> c;
    std::cin >> d1;
    std::cin >> operation;
    std::cin >> n2;
    std::cin >> c;
    std::cin >> d2;

    int n_result, d_result;
    switch (operation) {
      case '+': {
        n_result = n1*d2 + n2*d1;
        d_result = d1*d2;
        break;
      }
      case '-': {
        n_result = n1*d2 - n2*d1;
        d_result = d1*d2;
        break;
      }
      case '*': {
        n_result = n1*n2;
        d_result = d1*d2;
        break;
      }
      case '/': {
        n_result = n1*d2;
        d_result = n2*d1;
        break;
      }
      default: {
        assert(false);
      }
    }

    int divisor = gcd(n_result, d_result);
    int n_result_simplified = n_result / divisor;
    int d_result_simplified = d_result / divisor;
    if (d_result_simplified < 0) {
      n_result_simplified = -n_result_simplified;
      d_result_simplified = -d_result_simplified;
    }

    std::cout << n_result << "/" << d_result << " = "
      << n_result_simplified << "/" << d_result_simplified << std::endl;
  }

  return 0;
}
