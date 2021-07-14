#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

template <typename Type>
vector<Type> operator*(const vector<Type>& a, const vector<Type>& b);

template <typename Key, typename Value>
map<Key, Value> operator*(const map<Key, Value>& a, const map<Key, Value>& b);

template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& a, const pair<First, Second>& b);

template <typename Type>
Type Sqr(const Type& element);

template <typename Type>
vector<Type> operator*(const vector<Type>& a, const vector<Type>& b) {
  vector<Type> result(a.size());
  for (size_t i = 0; i < result.size(); i++) {
    result[i] = a.at(i) * b.at(i);
  }
  return result;
}

template <typename Key, typename Value>
map<Key, Value> operator*(const map<Key, Value>& a, const map<Key, Value>& b) {
  map<Key, Value> result;
  for (const auto& [key, value] : a) {
    result[key] = value * b.at(key);
  }
  return result;
}

template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& a, const pair<First, Second>& b) {
  First f = a.first * b.first;
  Second s = a.second * b.second;
  return make_pair(f, s);
}

template <typename Type>
Type Sqr(const Type& element) {
  return element * element;
}

int main() {
  vector<int> v = {1, 2, 3};
  cout << "vector:";
  for (int x : Sqr(v)) {
    cout << ' ' << x;
  }
  cout << endl;

  map<int, pair<int, int>> map_of_pairs = {{4, {2, 2}}, {7, {4, 3}}};
  cout << "map of pairs:" << endl;
  for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
  }

  return 0;
}
