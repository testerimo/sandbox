#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  map<string, string> capitals;

  cin >> n;

  for (int i = 0; i < n; i++) {
    string op;

    cin >> op;

    if (op == "CHANGE_CAPITAL") {
      string country;
      string new_capital;

      cin >> country >> new_capital;

      if (capitals[country] == new_capital) {
        cout << "Country " << country << " hasn't changed its capital" << endl;
      } else {
        if (capitals.count(country) == 0) {
          cout << "Introduce new country " << country << " with capital "
               << new_capital << endl;
        } else {
          cout << "Country " << country << " has changed its capital from "
               << capitals[country] << " to " << new_capital << endl;
        }

        capitals[country] = new_capital;
      }
    }

    if (op == "RENAME") {
      string old_country_name;
      string new_country_name;

      cin >> old_country_name >> new_country_name;

      if (old_country_name == new_country_name ||
          capitals.count(old_country_name) == 0 ||
          capitals.count(new_country_name) > 0) {
        cout << "Incorrect rename, skip" << endl;
      } else {
        capitals[new_country_name] = capitals[old_country_name];
        capitals.erase(old_country_name);
        cout << "Country " << old_country_name << " with capital "
             << capitals[new_country_name] << " has been renamed to "
             << new_country_name << endl;
      }
    }

    if (op == "ABOUT") {
      string country;

      cin >> country;

      if (capitals.count(country) == 0) {
        cout << "Country " << country << " doesn't exist" << endl;
      } else {
        cout << "Country " << country << " has capital " << capitals[country]
             << endl;
      }
    }

    if (op == "DUMP") {
      if (capitals.empty()) {
        cout << "There are no countries in the world" << endl;
      } else {
        for (const auto& [country, capital] : capitals) {
          cout << country << "/" << capital << " ";
        }
        cout << endl;
      }
    }
  }

  return 0;
}