// http://br.spoj.com/problems/JDENTIST/

#include <iostream>
#include <list>
#include <utility>

bool sortByEndingTime(std::pair<int, int> l, std::pair<int, int> r) {
  return l.second < r.second;
}

int main() {
  std::list<std::pair<int, int>> schedule;
  int n;
  std::cin >> n;
  while (n-- > 0) {
    int x, y;
    std::cin >> x >> y;
    schedule.push_back(std::make_pair(x, y));
  }

  schedule.sort(sortByEndingTime);
  std::pair<int, int> previous = *schedule.begin();
  schedule.erase(schedule.begin());
  int appointments = 1;
  bool search = true;

  std::list<std::pair<int, int>>::iterator it;
  while (search) {
    search = false;
    for (it = schedule.begin(); it != schedule.end(); ++it) {
      std::pair<int, int> next = *it;
      if (next.first >= previous.second) {
        previous = next;
        schedule.erase(it);
        ++appointments;
        search = true;
        break;
      }
    }
  }

  std::cout << appointments << std::endl;

  return 0;
}
