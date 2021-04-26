#include <vector>
#include <string>
#include <iostream>
using namespace std;

enum class Person { quiet, worried };

int main() {
  string op;
  int n;
  int k;

  cout << "Insert number of operations: ";
  cin >> n;

  vector<Person> people;

  for (int i = 1; i <= n; i++) {
    cout << "Operation " << i << ": ";
    cin >> op;

    if (op == "COME") {
      cin >> k;

      if (k <= 0) {
        people.resize(people.size() + k);
      } else {
        vector<Person> new_people(k, Person::quiet);
        people.insert(end(people), begin(new_people), end(new_people));
      }
    }

    if (op == "WORRY") {
      cin >> k;
      people[k] = Person::worried;
    }

    if (op == "QUIET") {
      cin >> k;
      people[k] = Person::quiet;
    }

    if (op == "WORRY_COUNT") {
      cout << count(begin(people), end(people), Person::worried) << endl;
    }
  }

  return 0;
}
