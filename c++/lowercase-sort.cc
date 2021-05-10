#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void PrintVector(const string& title, const vector<char>& v) {
  cout << title << ":";
  for (const auto& el : v) {
    cout << " " << el;
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;

  vector<char> v(n);

  for (auto& el : v) {
    cin >> el;
  }

  PrintVector("init", v);
  sort(begin(v), end(v),
       [](const char a, const char b) { return tolower(a) < tolower(b); });
  PrintVector("sort", v);

  return 0;
}
