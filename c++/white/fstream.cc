#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
  ifstream input("input.txt");
  ofstream output("output.txt");
  double line;

  if (input.is_open()) {
    cout << fixed << setprecision(3);

    while (input >> line) {  // or getline(input, line) but only for strings
      cout << line << endl;
      output << line << endl;
    }
  } else {
    cout << "Error: input file not found" << endl;
  }

  return 0;
}
