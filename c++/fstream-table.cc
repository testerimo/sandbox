#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main() {
  ifstream input("input.txt");
  ofstream output("output.txt");

  int n, m;
  input >> n;
  input.ignore(1);
  input >> m;

  output << fixed;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int k;
      input >> k;

      output << setw(10);
      output << k;

      if (j < m - 1) {
        input.ignore(1);
      }
    }

    if (i < n - 1) {
      output << endl;
    }
  }

  return 0;
}
