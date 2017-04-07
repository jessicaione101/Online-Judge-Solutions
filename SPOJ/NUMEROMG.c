// http://br.spoj.com/problems/NUMEROMG/

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10
#define TRUE 1
#define BASE 36

int dictionary10[100];
char dictionary36[36];

int convertToBase10(const char* n_base36, const int size) {
  int i, j = 0, n_base10 = 0;
  for (i = size-1; i >= 0; --i)
    n_base10 += dictionary10[(int)n_base36[i]] * pow(BASE, j++);
  return n_base10;
}

char* convertToBase36(const int n_base10, char* n_base36) {
  if (n_base10 < BASE) {
    *n_base36 = dictionary36[n_base10];
    *(n_base36+1) = '\0';
    return n_base36+1;
  }
  char* n_base36_ptr = convertToBase36(n_base10 / BASE, n_base36);
  *n_base36_ptr = dictionary36[n_base10 % BASE];
  *(n_base36_ptr+1) = '\0';
  return n_base36_ptr+1;
}

void buildDictionary10() {
  int i, j = 0;
  for (i = '0'; i <= '9'; ++i)
    dictionary10[i] = j++;
  for (i = 'A'; i <= 'Z'; ++i)
    dictionary10[i] = j++;
}

void buildDictionary36() {
  int i, j = 0;
  for (i = '0'; i <= '9'; ++i)
    dictionary36[j++] = i;
  for (i = 'A'; i <= 'Z'; ++i)
    dictionary36[j++] = i;
}

int main() {
  char a[MAX_SIZE], b[MAX_SIZE], output[MAX_SIZE];
  int i, input, a_base10, b_base10;
  buildDictionary10();
  buildDictionary36();

  while (TRUE) {
    i = 0;
    while ((input = getchar()) != ' ') {
      a[i++] = input;
    }
    a[i++] = '\0';
    a_base10 = convertToBase10(a, i-1);

    i = 0;
    while ((input = getchar()) != '\n' && input != EOF) {
      b[i++] = input;
    }
    b[i++] = '\0';
    b_base10 = convertToBase10(b, i-1);

    if (a_base10 == 0 && b_base10 == 0)
      break;

    convertToBase36(a_base10 + b_base10, output);
    printf("%s\n", output);
  }

  return 0;
}
