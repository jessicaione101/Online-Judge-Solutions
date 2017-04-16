// http://br.spoj.com/problems/NUMERDOS/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <queue>

int main() {
  std::pair<std::string, std::string> erdos{"Erdos", "P."};
  int a, test = 0;
  std::cin >> a;
  while (a != 0) {
    std::vector<std::vector<int>> publications(100);
    std::map<std::pair<std::string, std::string>, int> authors;
    int index = 0;
    authors[erdos] = index++;

    while (a-- > 0) {
      std::string name, surname;
      std::vector<std::pair<std::string, std::string>> related_authors;
      do {
        std::cin >> name >> surname;
        std::pair<std::string, std::string> author{
          std::string(surname.begin(), surname.end()-1), name};
        if (authors.find(author) == authors.end())
          authors[author] = index++;
        related_authors.push_back(author);
      } while (*(surname.end()-1) != '.');

      for (size_t i = 0; i < related_authors.size(); ++i)
        for (size_t j = 0; j < related_authors.size(); ++j) {
          if (i != j)
          publications[authors[related_authors[i]]]
            .push_back(authors[related_authors[j]]);
        }
      related_authors.clear();
    }

    std::vector<int> authors_erdos_numbers(authors.size(), -1);
    authors_erdos_numbers[0] = 0;
    std::queue<int> processing;
    processing.push(0);
    while (!processing.empty()) {
      int author = processing.front();
      processing.pop();
      for (size_t i = 0; i < publications[author].size(); ++i) {
        if (authors_erdos_numbers[publications[author][i]] < 0) {
          authors_erdos_numbers[publications[author][i]]
            = authors_erdos_numbers[author] + 1;
          processing.push(publications[author][i]);
        }
      }
    }

    std::cout << "Teste " << ++test << std::endl;
    std::map<std::pair<std::string, std::string>, int>::iterator it;
    for (it = authors.begin(); it != authors.end(); ++it) {
      if (it->second != 0) {
        std::cout << (*it).first.second << " " << (*it).first.first << ": ";
        int erdos_number = authors_erdos_numbers[it->second];
        if (erdos_number == -1)
          std::cout << "infinito";
        else
          std::cout << erdos_number;
        std::cout << std::endl;
      }
    }
    std::cout << std::endl;
    std::cin >> a;
  }
  return 0;
}

