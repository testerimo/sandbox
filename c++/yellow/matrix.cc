#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Matrix {
 public:
  Matrix() {
    matrix = {};
    num_rows_ = 0;
    num_cols_ = 0;
  }

  Matrix(int num_rows, int num_cols) {
    Reset(num_rows, num_cols);
  }

  void Reset(int num_rows, int num_cols) {
    if (num_rows < 0) {
      throw out_of_range("Number of rows must be >= 0");
    }

    if (num_cols < 0) {
      throw out_of_range("Number of columns must be >= 0");
    }

    if (num_rows == 0 || num_cols == 0) {
      num_rows_ = 0;
      num_cols_ = 0;
    } else {
      num_rows_ = num_rows;
      num_cols_ = num_cols;
    }

    matrix.assign(num_rows_, vector<int>(num_cols_));
  }

  int At(int row, int col) const {
    return matrix.at(row).at(col);
  }

  int& At(int row, int col) {
    return matrix.at(row).at(col);
  }

  int GetNumRows() const {
    return num_rows_;
  }

  int GetNumColumns() const {
    return num_cols_;
  }

 private:
  vector<vector<int>> matrix;
  int num_rows_;
  int num_cols_;
};

istream& operator>>(istream& stream, Matrix& matrix) {
  int num_rows, num_cols;

  stream >> num_rows >> num_cols;

  matrix.Reset(num_rows, num_cols);

  for (size_t row = 0; row < matrix.GetNumRows(); row++) {
    for (size_t col = 0; col < matrix.GetNumColumns(); col++) {
      stream >> matrix.At(row, col);
    }
  }

  return stream;
}

ostream& operator<<(ostream& stream, const Matrix& matrix) {
  stream << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;

  for (size_t row = 0; row < matrix.GetNumRows(); row++) {
    for (size_t col = 0; col < matrix.GetNumColumns(); col++) {
      if (col > 0) {
        stream << " ";
      }

      stream << matrix.At(row, col);
    }

    stream << endl;
  }

  return stream;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
  if (lhs.GetNumRows() != rhs.GetNumRows()) {
    return false;
  }

  if (rhs.GetNumRows() != rhs.GetNumColumns()) {
    return false;
  }

  for (size_t row = 0; row < lhs.GetNumRows(); row++) {
    for (size_t col = 0; col < lhs.GetNumColumns(); col++) {
      if (lhs.At(row, col) != rhs.At(row, col)) {
        return false;
      }
    }
  }

  return true;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
  if (lhs.GetNumRows() != rhs.GetNumRows()) {
    throw invalid_argument("Number of rows must be the same");
  }

  if (lhs.GetNumColumns() != rhs.GetNumColumns()) {
    throw invalid_argument("Number of cols must be the same");;
  }

  Matrix result(lhs.GetNumRows(), lhs.GetNumColumns());

  for (size_t row = 0; row < result.GetNumRows(); row++) {
    for (size_t col = 0; col < result.GetNumColumns(); col++) {
      result.At(row, col) = lhs.At(row, col) + rhs.At(row, col);
    }
  }

  return result;
}

int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;

  return 0;
}