#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void PrintVector(const vector<int>& v) {
  for (const int& x : v) {
    cout << x << " ";
  }
  cout << endl;
}

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  if (range_end - range_begin < 2) {
    return;
  }

  vector<typename RandomIt::value_type> elements(range_begin, range_end);
  auto border = begin(elements) + elements.size() / 2;

  MergeSort(begin(elements), border);
  MergeSort(border, end(elements));

  merge(begin(elements), border, border, end(elements), range_begin);
};

template <typename RandomIt>
void MergeSort3(RandomIt range_begin, RandomIt range_end) {
  if (range_end - range_begin < 2) {
    return;
  }

  vector<typename RandomIt::value_type> elements(range_begin, range_end);
  auto border1 = begin(elements) + elements.size() / 3;
  auto border2 = end(elements) - elements.size() / 3;

  MergeSort(begin(elements), border1);
  MergeSort(border1, border2);
  MergeSort(border2, end(elements));

  vector<int> temp;

  merge(begin(elements), border1, border1, border2, back_inserter(temp));
  merge(begin(temp), end(temp), border2, end(elements), range_begin);
}

int main() {
  vector<int> v2 = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v2), end(v2));
  PrintVector(v2);

  vector<int> v3 = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort3(begin(v3), end(v3));
  PrintVector(v3);

  return 0;
}
