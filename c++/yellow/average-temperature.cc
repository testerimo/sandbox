#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int64_t> temps(n);
  int64_t sum;

  for (auto& temp : temps) {
    cin >> temp;
    sum += temp;
  }

  double average = sum / static_cast<double>(temps.size());

  vector<int> days;

  for (int i = 0; i < temps.size(); i++) {
    if (temps[i] > average) {
      days.push_back(i);
    }
  }

  cout << days.size() << endl;

  for (const auto& day : days) {
    cout << day << " ";
  }

  cout << endl;

  return 0;
}
