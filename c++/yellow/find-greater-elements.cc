#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border){
  auto found = find_if(
    begin(elements),
    end(elements),
    [border](T el) { return el > border; }
  );

  vector<T> result;

  for (auto it = found; it != end(elements); ++it) {
    result.push_back(*it);
  }

  return result;
};

template <typename T>
vector<T> BetterFindGreaterElements(const set<T>& elements, const T& border){
  auto it = find_if(
    begin(elements),
    end(elements),
    [border](T el) { return el > border; }
  );

  return {it, end(elements)};
};

int main() {
  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
    cout << x << " ";
  }
  cout << endl;

  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}
