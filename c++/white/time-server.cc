#include <exception>
#include <iostream>
#include <string>
using namespace std;

string AskTimeServer() {
  // return "16:41:55";

  throw system_error(ENETDOWN, generic_category(), "Connection lost");

  // throw domain_error("Other error");
}

class TimeServer {
 public:
  string GetCurrentTime() {
    try {
      last_fetched_time = AskTimeServer();
      return last_fetched_time;
    } catch (system_error& e) {
      return last_fetched_time;
    } catch (exception& e) {
      throw e;
    }
  }

 private:
  string last_fetched_time = "00:00:00";
};

int main() {
  TimeServer ts;
  try {
    cout << ts.GetCurrentTime() << endl;
  } catch (exception& e) {
    cout << "Exception got: " << e.what() << endl;
  }
  return 0;
}
