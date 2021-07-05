#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Rational {
 public:
  Rational() {
    numerator = 0;
    denominator = 1;
  }

  Rational(int new_numerator, int new_denominator) {
    if (new_denominator == 0) {
      throw invalid_argument("Invalid argument");
    }

    int gcd = GreatestCommonDivisor(abs(new_numerator), abs(new_denominator));

    numerator = new_numerator / gcd;
    denominator = new_denominator / gcd;

    if (denominator < 0) {
      numerator = -numerator;
      denominator = -denominator;
    }
  }

  int Numerator() const {
    return numerator;
  }

  int Denominator() const {
    return denominator;
  }

 private:
  int numerator;
  int denominator;

  int GreatestCommonDivisor(int a, int b) {
    if (a == 0 || a == b) {
      return b;
    }

    if (a < b) {
      return GreatestCommonDivisor(b % a, a);
    } else {
      return GreatestCommonDivisor(a % b, b);
    }
  }
};

Rational operator+(const Rational& lhs, const Rational& rhs) {
  return Rational(
    lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
    lhs.Denominator() * rhs.Denominator()
  );
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
  return Rational(
    lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
    lhs.Denominator() * rhs.Denominator()
  );
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
  return Rational(
    lhs.Numerator() * rhs.Numerator(),
    lhs.Denominator() * rhs.Denominator()
  );
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
  if (rhs.Numerator() == 0) {
    throw domain_error("Division by zero");
  }

  return Rational(
    lhs.Numerator() * rhs.Denominator(),
    lhs.Denominator() * rhs.Numerator()
  );
}

bool operator==(const Rational& lhs, const Rational& rhs) {
  return lhs.Numerator() == rhs.Numerator() &&
         lhs.Denominator() == rhs.Denominator();
}

bool operator<(const Rational& lhs, const Rational& rhs) {
  return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
}

istream& operator>>(istream& stream, Rational& rational) {
  int numerator, denominator;
  char sign;

  stream >> numerator >> sign >> denominator;

  if (stream && sign == '/') {
    rational = Rational(numerator, denominator);
  }

  return stream;
}

ostream& operator<<(ostream& stream, const Rational& rational) {
  stream << rational.Numerator() << "/" << rational.Denominator();
  return stream;
}
