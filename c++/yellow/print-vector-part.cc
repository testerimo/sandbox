#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void PrintVectorPart(const vector<int>& numbers){
  auto it = find_if(
    begin(numbers),
    end(numbers),
    [](int n) { return n < 0; }
  );

  while (it != begin(numbers)) {
    --it;
    cout << *it << " ";
  }
}

int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}
