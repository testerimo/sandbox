#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
  map<int, set<string>> bus_routes;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    set<string> new_route;
    int stop_count;

    cin >> stop_count;

    for (int j = 0; j < stop_count; j++) {
      string stop;
      cin >> stop;
      new_route.insert(stop);
    }

    int bus_found = -1;

    for (const auto& [bus, route] : bus_routes) {
      if (new_route == route) {
        bus_found = bus;
        break;
      }
    }

    if (bus_found != -1) {
      cout << "Already exists for " << bus_found << endl;
      continue;
    }

    int new_bus = bus_routes.size() + 1;
    bus_routes[new_bus] = new_route;

    cout << "New bus " << new_bus << endl;
  }

  return 0;
}