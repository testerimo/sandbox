#include <iostream>
#include <string>

#include "rational.cc"
using namespace std;

Rational CalculateRational(char sign, const Rational& a, const Rational& b) {
  switch (sign) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
    default:
      throw exception();
  }
}

int main() {
  Rational a, b;
  char sign;

  try {
    cin >> a >> sign >> b;
    cout << CalculateRational(sign, a, b);
  } catch (invalid_argument& ex) {
    cout << ex.what() << endl;
  } catch (domain_error& ex) {
    cout << ex.what() << endl;
  } catch (exception& ex) {
    cout << "Bad operation" << endl;
  }

  return 0;
}
