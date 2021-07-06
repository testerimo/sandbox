#include <iostream>
#include <map>
#include <string>
using namespace std;

class Person {
 public:
  void ChangeFirstName(int year, const string& first_name) {
    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    last_names[year] = last_name;
  }
  string GetFullName(int year) {
    string first_name = FindName(year, first_names);
    string last_name = FindName(year, last_names);

    if (first_name.empty() && last_name.empty()) {
      return "Incognito";
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";
    }

    return first_name + " " + last_name;
  }

 private:
  map<int, string> first_names;
  map<int, string> last_names;

  string FindName(int year, map<int, string> names) {
    string name = "";
    for (const auto& [y, n] : names) {
      if (y <= year) {
        name = n;
      } else {
        break;
      }
    }
    return name;
  }
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}
