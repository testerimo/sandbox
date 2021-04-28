#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  map<vector<string>, int> bus_routes;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int k;

    cin >> k;

    vector<string> route(k);

    for (int j = 0; j < k; j++) {
      cin >> route[j];
    }

    if (bus_routes.count(route) != 0) {
      cout << "Already exists for " << bus_routes[route] << endl;
    } else {
      int bus = bus_routes.size() + 1;
      bus_routes[route] = bus;
      cout << "New bus " << bus << endl;
    }
  }

  return 0;
}
