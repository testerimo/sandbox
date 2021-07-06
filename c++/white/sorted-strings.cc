#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SortedStrings {
 public:
  void AddString(const string& s) {
    strings.push_back(s);
    unsorted = true;
  }
  vector<string> GetSortedStrings() {
    if (unsorted) {
      sort(begin(strings), end(strings));
      unsorted = false;
    }
    return strings;
  }

 private:
  vector<string> strings;
  bool unsorted = false;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;

  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);

  strings.AddString("second");
  PrintSortedStrings(strings);

  return 0;
}
