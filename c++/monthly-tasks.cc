#include <iostream>
#include <string>
#include <vector>
using namespace std;

void PrintTasks(const vector<string>& tasks) {
  cout << tasks.size();
  for (const auto& task : tasks) {
    cout << " " << task;
  }
  cout << endl;
}

void GoToNextMonth(
  const int prev_month,
  vector<vector<string>>& tasks_for_day,
  const vector<int>& days_in_month
) {
  const int active_month = prev_month == 11 ? 0 : prev_month + 1;
  const int new_days = days_in_month[active_month];
  int diff_days = tasks_for_day.size() - new_days;

  if (diff_days > 0) {
    vector<string> tasks;

    while (diff_days > 0) {
      int day = tasks_for_day.size() - diff_days;
      tasks.insert(end(tasks), begin(tasks_for_day[day]), end(tasks_for_day[day]));
      diff_days--;
    }

    tasks_for_day[new_days - 1] = tasks;
  }

  tasks_for_day.resize(new_days);
}

int main() {
  int n;
  int active_month = 0;
  const vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  vector<vector<string>> tasks_for_day(days_in_month[active_month]);

  cout << "Insert number of operations: ";
  cin >> n;

  for (int i = 1; i <= n; i++) {
    int day;
    string op;
    string task;

    cout << "Operation " << i << ": ";
    cin >> op;

    if (op == "ADD") {
      cin >> day >> task;
      tasks_for_day[day - 1].push_back(task);
    }

    if (op == "DUMP") {
      cin >> day;
      PrintTasks(tasks_for_day[day - 1]);
    }

    if (op == "NEXT") {
      GoToNextMonth(active_month, tasks_for_day, days_in_month);
    }
  }

  return 0;
}
