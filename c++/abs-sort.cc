#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void PrintVector(const string& title, const vector<int> v) {
  cout << title << ":";
  for (const auto& el : v) {
    cout << " " << el;
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;

  vector<int> numbers(n);

  for (auto& num : numbers) {
    cin >> num;
  }

  PrintVector("init", numbers);
  sort(begin(numbers), end(numbers),
       [](const int a, const int b) { return abs(a) < abs(b); });
  PrintVector("sort", numbers);

  return 0;
}