// http://br.spoj.com/problems/PAPRIMAS/

#include <stdio.h>

#define MAX_SIZE 30

int dictionary[200];

char* isPrime(const int n) {
  if (n <= 3)
    return "It is a prime word.";
  if (n % 2 == 0 || n % 3 == 0)
    return "It is not a prime word.";

  int divisor = 5;
  while (divisor*divisor <= n) {
    if (n % divisor == 0 || n % (divisor+2) == 0)
      return "It is not a prime word.";
    divisor += 6;
  }

  return "It is a prime word.";
}

int wordToNumber(char* word) {
  int i, sum = 0;
  for (i = 0; word[i] != '\0'; ++i)
    sum += dictionary[(int)word[i]];
  return sum;
}

void buildDictionary() {
  int i, j = 0;
  for (i = 'a'; i <= 'z'; ++i)
    dictionary[i] = ++j;
  for (i = 'A'; i <= 'Z'; ++i)
    dictionary[i] = ++j;
}

int main() {
  char word[MAX_SIZE];
  buildDictionary();

  while ((scanf("%s", word)) != EOF) {
    printf("%s\n", isPrime(wordToNumber(word)));
  }

  return 0;
}
