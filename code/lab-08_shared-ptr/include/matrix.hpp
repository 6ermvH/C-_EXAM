#ifndef LAB_08_MATRIX_H
#define LAB_08_MATRIX_H

#include <cstddef>
#include <cstdio>

class Matrix {
 public:
  Matrix(std::size_t r, std::size_t c);
  Matrix(const Matrix& matrix);
  ~Matrix();

  Matrix& operator=(const Matrix& matrix);

  std::size_t get_rows() const;
  std::size_t get_cols() const;
  void set(std::size_t i, std::size_t j, int val);
  int get(std::size_t i, std::size_t j) const;
  void print(FILE* f) const;

  Matrix& operator+=(const Matrix& m);
  Matrix& operator-=(const Matrix& m);
  Matrix& operator*=(const Matrix& m);

  friend Matrix operator+(const Matrix& m1, const Matrix& m2);
  friend Matrix operator-(const Matrix& m1, const Matrix& m2);
  friend Matrix operator*(const Matrix& m1, const Matrix& m2);

  friend bool operator==(const Matrix& m1, const Matrix& m2);
  friend bool operator!=(const Matrix& m1, const Matrix& m2);

 private:
  int** allocated_2d_array_int(std::size_t _rows, std::size_t cols);

  std::size_t _rows;
  std::size_t _cols;
  int** _data;
};

#endif
