#include "matrix.hpp"

#include <cassert>
#include <iostream>

int** Matrix::allocated_2d_array_int(std::size_t rows, std::size_t cols) {
  int** data = new int*[rows];
  for (std::size_t i = 0; i < rows; ++i) {
    data[i] = new int[cols];
  }
  return data;
}

Matrix::Matrix(std::size_t r, std::size_t c) : _rows(r), _cols(c) {
  assert(r > 0 && c > 0 && "OUT_OF_BOUNDS");
  _data = allocated_2d_array_int(_rows, _cols);
  for (std::size_t i = 0; i < _rows; ++i) {
    for (std::size_t j = 0; j < _cols; ++j) {
      _data[i][j] = 0;
    }
  }
}

Matrix::Matrix(const Matrix& matrix) {
  _data = nullptr;
  *this = matrix;
}

Matrix& Matrix::operator=(const Matrix& matrix) {
  if (this == &matrix) {
    return *this;
  }
  this->~Matrix();
  _rows = matrix.get_rows();
  _cols = matrix.get_cols();
  _data = allocated_2d_array_int(_rows, _cols);
  for (std::size_t i = 0; i < _rows; ++i) {
    for (std::size_t j = 0; j < _cols; ++j) {
      _data[i][j] = matrix.get(i, j);
    }
  }
  return *this;
}

Matrix::~Matrix() {
  if (!_data) {
    return;
  }
  for (std::size_t i = 0; i < _rows; ++i) {
    delete[] _data[i];
  }
  if (_data != nullptr) delete[] _data;
}

std::size_t Matrix::get_rows() const { return _rows; }
std::size_t Matrix::get_cols() const { return _cols; }

void Matrix::set(std::size_t i, std::size_t j, int val) { _data[i][j] = val; }

int Matrix::get(std::size_t i, std::size_t j) const { return _data[i][j]; }

void Matrix::print(FILE* f) const {
  for (std::size_t i = 0; i < _rows; ++i) {
    for (std::size_t j = 0; j < _cols; ++j) {
      if (0 < j) {
        fprintf(f, " ");
      }
      fprintf(f, "%d", _data[i][j]);
    }
    fprintf(f, "\n");
  }
}

Matrix& Matrix::operator+=(const Matrix& m) {
  for (std::size_t i = 0; i < _rows; ++i) {
    for (std::size_t j = 0; j < _cols; ++j) {
      _data[i][j] += m.get(i, j);
    }
  }
  return *this;
}

Matrix& Matrix::operator-=(const Matrix& m) {
  for (std::size_t i = 0; i < _rows; ++i) {
    for (std::size_t j = 0; j < _cols; ++j) {
      _data[i][j] -= m.get(i, j);
    }
  }
  return *this;
}

Matrix& Matrix::operator*=(const Matrix& m) {
  Matrix tmp = *this;
  *this = Matrix(tmp.get_rows(), m.get_cols());
  for (std::size_t i = 0; i < _rows; ++i) {
    for (std::size_t j = 0; j < _cols; ++j) {
      for (std::size_t q = 0; q < tmp.get_cols(); ++q) {
        _data[i][j] += tmp.get(i, q) * m.get(q, j);
      }
    }
  }
  return *this;
}

Matrix operator+(const Matrix& m1, const Matrix& m2) {
  Matrix result = m1;
  return result += m2;
}

Matrix operator-(const Matrix& m1, const Matrix& m2) {
  Matrix result = m1;
  return result -= m2;
}

Matrix operator*(const Matrix& m1, const Matrix& m2) {
  Matrix result = m1;
  return result *= m2;
}

bool operator==(const Matrix& m1, const Matrix& m2) {
  if (m1.get_rows() != m2.get_rows() || m1.get_cols() != m2.get_cols()) {
    return false;
  }
  for (std::size_t i = 0; i < m1.get_rows(); ++i) {
    for (std::size_t j = 0; j < m1.get_cols(); ++j) {
      if (m1.get(i, j) != m2.get(i, j)) {
        return false;
      }
    }
  }
  return true;
}

bool operator!=(const Matrix& m1, const Matrix& m2) { return !(m1 == m2); }
