#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
using namespace std;

void EnsureDateSymbolAndSkip(stringstream& stream) {
  if (stream.peek() != '-') {
    throw exception();
  }

  stream.ignore(1);
}

class Date {
 public:
  Date() {
    year = 0;
    month = 1;
    day = 1;
  }

  Date(int new_year, int new_month, int new_day) {
    if (new_month < 1 || 12 < new_month) {
      throw invalid_argument("Month value is invalid: " + to_string(new_month));
    }

    if (new_day < 1 || 31 < new_day) {
      throw invalid_argument("Day value is invalid: " + to_string(new_day));
    }

    year = new_year;
    month = new_month;
    day = new_day;
  }

  int GetYear() const {
    return year;
  }

  int GetMonth() const {
    return month;
  }

  int GetDay() const {
    return day;
  }

 private:
  int year;
  int month;
  int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
  if (lhs.GetYear() != rhs.GetYear()) {
    return lhs.GetYear() < rhs.GetYear();
  } else if (lhs.GetMonth() != rhs.GetMonth()) {
    return lhs.GetMonth() < rhs.GetMonth();
  } else {
    return lhs.GetDay() < rhs.GetDay();
  }
}

istream& operator>>(istream& stream, Date& date) {
  string source_date;
  stringstream sstream;
  int year, month, day;

  stream >> source_date;
  sstream << source_date;

  try {
    sstream >> year;
    EnsureDateSymbolAndSkip(sstream);
    sstream >> month;
    EnsureDateSymbolAndSkip(sstream);
    sstream >> day;
  } catch (exception& e) {
    throw domain_error("Wrong date format: " + source_date);
  }

  date = Date(year, month, day);

  return stream;
}

ostream& operator<<(ostream& stream, const Date& date) {
  stream << setfill('0');
  stream << setw(4) << date.GetYear() << "-"
         << setw(2) << date.GetMonth() << "-"
         << setw(2) << date.GetDay();
  return stream;
}

class Database {
 public:
  void AddEvent(const Date& date, const string& event) {
    records[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const string& event) {
    if (records.count(date) && records.at(date).count(event)) {
      records.at(date).erase(event);
      return true;
    } else {
      return false;
    }
  }

  int DeleteDate(const Date& date) {
    int count = 0;

    if (records.count(date)) {
      count = records.at(date).size();
      records.erase(date);
    };

    return count;
  }

  set<string> Find(const Date& date) const {
    set<string> result;

    if (records.count(date)) {
      result = records.at(date);
    }

    return result;
  }

  void Print() const {
    for (const auto& [date, events] : records) {
      for (const auto& event : events) {
        cout << date << " " << event << endl;
      }
    }
  };

 private:
  map<Date, set<string>> records;
};

int main() {
  Database db;
  string line;

  while (getline(cin, line)) {
    stringstream sstream(line);
    string command;

    sstream >> command;

    try {
      if (command == "Add") {
        Date date;
        string event;

        sstream >> date >> event;
        db.AddEvent(date, event);
      } else if (command == "Del") {
        Date date;
        string event;

        sstream >> date >> event;

        if (event.empty()) {
          int count = db.DeleteDate(date);

          cout << "Deleted " << count << " events" << endl;
        } else {
          bool deleted = db.DeleteEvent(date, event);

          if (deleted) {
            cout << "Deleted successfully" << endl;
          } else {
            cout << "Event not found" << endl;
          }
        }
      } else if (command == "Find") {
        Date date;
        sstream >> date;

        set<string> found = db.Find(date);

        if (found.empty()) {
          cout << "Date not found" << endl;
        } else {
          for (const auto& event : found) {
            cout << event << endl;
          }
        }
      } else if (command == "Print") {
        db.Print();
      } else if (command == "") {
        continue;
      } else {
        cout << "Unknown command: " << command << endl;
      }
    } catch (exception& e) {
      cout << e.what() << endl;
    }
  }

  return 0;
}
