#include <iostream>
#include <map>
#include <string>
using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& item, const Key& key) {
  try {
    return item.at(key);
  } catch (out_of_range& e) {
    throw runtime_error(e.what());
  }
}

int main() {
  map<int, string> m = {{0, "value"}};
  string& item = GetRefStrict(m, 4);
  item = "newvalue";
  cout << m[0] << endl;  // выведет newvalue
}