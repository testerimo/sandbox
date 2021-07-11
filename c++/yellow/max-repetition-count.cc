#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};

tuple<string, string, map<Lang, string>, int64_t> GetRegionRank(const Region& region) {
  return tie(region.std_name, region.parent_std_name, region.names, region.population);
}

// for 1st and 2nd solutions
bool operator==(const Region& one, const Region& two) {
  return GetRegionRank(one) == GetRegionRank(two);
}

// for 3rd solution
bool operator<(const Region& one, const Region& two) {
  return GetRegionRank(one) < GetRegionRank(two);
}

// 1st solution
int WorstFindMaxRepetitionCount(const vector<Region>& regions) {
  vector<bool> counted(regions.size(), false);

  int max_repetition_count = 0;
  int current_repetition_count = 0;

  for (size_t i = 0; i < regions.size(); i++) {
    if (counted[i]) {
      continue;
    }

    const Region& one_region = regions.at(i);

    for (size_t j = 0; j < regions.size(); j++) {
      const Region& two_region = regions.at(j);

      if (one_region == two_region) {
        current_repetition_count++;
        counted[i] = true;
      }
    }

    max_repetition_count = max(max_repetition_count, current_repetition_count);
    current_repetition_count = 0;
  }

  return max_repetition_count;
};

// 2nd solution
int BadFindMaxRepetitionCount(const vector<Region>& regions) {
  int max_repetition_count = 0;
  int current_repetition_count = 0;

  for (const auto& region : regions) {
    current_repetition_count = count(begin(regions), end(regions), region);
    max_repetition_count = max(current_repetition_count, max_repetition_count);
  }

  return max_repetition_count;
}

// 3rd soultion
int FindMaxRepetitionCount(const vector<Region>& regions) {
  map<Region, int> repetition_counts;
  int max_repetition_count = 0;

  for (const auto& region : regions) {
    max_repetition_count = max(max_repetition_count, ++repetition_counts[region]);
  }

  return max_repetition_count;
}

int main() {
  cout << FindMaxRepetitionCount({
    {
      "Moscow",
      "Russia",
      {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
      89
    }, {
      "Russia",
      "Eurasia",
      {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
      89
    }, {
      "Moscow",
      "Russia",
      {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
      89
    }, {
      "Moscow",
      "Russia",
      {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
      89
    }, {
      "Russia",
      "Eurasia",
      {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
      89
    },
  }) << endl;

  cout << FindMaxRepetitionCount({
    {
      "Moscow",
      "Russia",
      {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
      89
    }, {
      "Russia",
      "Eurasia",
      {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
      89
    }, {
      "Moscow",
      "Russia",
      {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
      89
    }, {
      "Moscow",
      "Toulouse",
      {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
      89
    }, {
      "Moscow",
      "Russia",
      {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
      31
    },
  }) << endl;

  return 0;
}
