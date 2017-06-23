// https://www.urionlinejudge.com.br/judge/en/problems/view/1790

#include <iostream>
#include <vector>
#include <algorithm>

const int kUndefined = -1;

struct City {
  int depth;
  int min_depth;
  int parent;
  std::vector<int> adjacent_cities;
  City() : depth(kUndefined), min_depth(kUndefined), parent(kUndefined) {}
};

class Country {
 public:
  explicit Country(const int n) {
    cities.resize(n);
    non_cycle_bridges = 0;
  }

  void AddBridge(const int city_a, const int city_b) {
    cities[city_a].adjacent_cities.push_back(city_b);
    cities[city_b].adjacent_cities.push_back(city_a);
  }

  void AddNonCycleBridge() {
    ++non_cycle_bridges;
  }

  int GetNonCycleBridges() const {
    return non_cycle_bridges;
  }

  int GetDepth(const int city) const {
    return cities[city].depth;
  }

  int GetMinDepth(const int city) const {
    return cities[city].min_depth;
  }

  int GetParent(const int city) const {
    return cities[city].parent;
  }

  std::vector<int> GetAdjacentCities(const int city) const {
    return cities[city].adjacent_cities;
  }

  void SetDepth(const int city, const int depth) {
    cities[city].depth = depth;
  }

  void SetMinDepth(const int city, const int min_depth) {
    cities[city].min_depth = min_depth;
  }

  void SetParent(const int city, const int parent) {
    cities[city].parent = parent;
  }

 private:
  std::vector<City> cities;
  int non_cycle_bridges;
};

void CountNonCycleBridges(Country* country, const int parent, const int depth) {
  (*country).SetDepth(parent, depth);
  (*country).SetMinDepth(parent, depth);

  std::vector<int> adjacent_cities = (*country).GetAdjacentCities(parent);
  for (size_t i = 0; i < adjacent_cities.size(); ++i) {
    int next_city = adjacent_cities[i];

    if ((*country).GetDepth(next_city) == kUndefined) {
      (*country).SetParent(next_city, parent);
      CountNonCycleBridges(country, next_city, depth+1);

      if ((*country).GetMinDepth(next_city) > (*country).GetDepth(parent))
        (*country).AddNonCycleBridge();

      (*country).SetMinDepth(parent, std::min((*country).GetMinDepth(parent),
        (*country).GetMinDepth(next_city)));
    } else if (next_city != (*country).GetParent(parent)) {
      (*country).SetMinDepth(parent, std::min((*country).GetMinDepth(parent),
        (*country).GetDepth(next_city)));
    }
  }
}

int main() {
  int c, p;
  while (std::cin >> c >> p) {
    Country country(c);

    int x, y;
    while (p-- > 0) {
      std::cin >> x >> y;
      --x, --y;
      country.AddBridge(x, y);
    }

    CountNonCycleBridges(&country, 0, 0);
    std::cout << country.GetNonCycleBridges() << std::endl;
  }

  return 0;
}
