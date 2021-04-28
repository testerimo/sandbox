#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void PrintVector(const vector<string>& v) {
  for (const auto& elem : v) {
    cout << elem << " ";
  }
  cout << endl;
}

int main() {
  int n;
  map<string, vector<string>> bus_routes;

  cin >> n;

  for (int i = 0; i < n; i++) {
    string op;

    cin >> op;

    if (op == "NEW_BUS") {
      string bus;
      int stop_count;

      cin >> bus >> stop_count;

      vector<string> route(stop_count);

      for (int j = 0; j < stop_count; j++) {
        cin >> route[j];
      }

      bus_routes[bus] = route;
    }

    if (op == "BUSES_FOR_STOP") {
      vector<string> buses;
      string bus_stop;

      cin >> bus_stop;

      for (auto& [bus, route] : bus_routes) {
        if (count(begin(route), end(route), bus_stop) != 0) {
          buses.push_back(bus);
        }
      }

      if (buses.size() == 0) {
        cout << "No stop" << endl;
      } else {
        PrintVector(buses);
      }
    }

    if (op == "STOPS_FOR_BUS") {
      string bus;
      cin >> bus;

      if (bus_routes.count(bus) == 0) {
        cout << "No bus" << endl;
      } else {
        for (auto& bus_stop : bus_routes[bus]) {
          vector<string> interchanges;

          for (auto& [other_bus, route] : bus_routes) {
            if (bus == other_bus) {
              continue;
            }

            if (count(begin(route), end(route), bus_stop)) {
              interchanges.push_back(other_bus);
            }
          }

          cout << "Stop " << bus_stop << ": ";

          if (interchanges.size() == 0) {
            cout << "no interchange" << endl;
          } else {
            PrintVector(interchanges);
          }
        }
      }
    }

    if (op == "ALL_BUSES") {
      if (bus_routes.empty()) {
        cout << "No buses" << endl;
      } else {
        for (const auto& [bus, route] : bus_routes) {
          cout << "Bus " << bus << ": ";
          PrintVector(route);
        }
      }
    }
  }

  return 0;
}
