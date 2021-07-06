#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
  string first_name;
  string last_name;
  int day;
  int month;
  int year;
};

int main() {
  vector<Student> students;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int day, month, year;
    string first_name, last_name;

    cin >> first_name >> last_name >> day >> month >> year;

    students.push_back({first_name, last_name, day, month, year});
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int index;
    string op;
    cin >> op >> index;

    if (index < 1 || n < index) {
      cout << "bad request" << endl;
      continue;
    }

    Student found = students[index - 1];

    if (op == "name") {
      cout << found.first_name << " " << found.last_name << endl;
    } else if (op == "date") {
      cout << found.day << "." << found.month << "." << found.year << endl;
    } else {
      cout << "bad request" << endl;
    }
  }

  return 0;
}
