#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

void PrintVector(const vector<int>& v) {
  for (const auto& el : v) {
    cout << el << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;

  vector<int> v;

  for (int i = n; i > 0; --i) {
    v.push_back(i);
  }

  PrintVector(v);

  while (prev_permutation(begin(v), end(v))) {
    PrintVector(v);
  }

  return 0;
}
