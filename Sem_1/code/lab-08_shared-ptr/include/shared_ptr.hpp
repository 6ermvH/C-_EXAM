#pragma once

#include "matrix.hpp"

class shared_ptr {
 public:
  /**
   * Получает объект по сырому указателю во владение.
   * Передача того же указателя во владение кому либо ещё — неопределённое
   * поведение.
   */
  shared_ptr(Matrix* obj = nullptr);
  /**
   * Строит копию умного указателя, разделяя владение с оригиналом.
   */
  shared_ptr(const shared_ptr& other);
  /**
   * Присваивает умному указателю новое значение, корректно меняя владение с
   * одного объекта на другой.
   */
  shared_ptr& operator=(shared_ptr other);
  ~shared_ptr();

  /**
   * Возвращает сырой указатель для несовместимого кода.
   */
  Matrix* ptr() const;
  /**
   * Проверка на nullptr.
   */
  bool isNull() const;
  /**
   * Присваивает умному указателю новый для владения.
   */
  void reset(Matrix* obj = nullptr);

  Matrix* operator->() const;
  Matrix& operator*() const;

 private:
  class Storage {
   public:
    Storage(Matrix* mtx) : data_(mtx), ref_count_(1) {}
    ~Storage() { delete data_; }

    void incr() { ++ref_count_; }
    void decr() { --ref_count_; }

    int getCounter() const { return ref_count_; }
    Matrix* getObject() const { return data_; }

   private:
    Matrix* data_;
    int ref_count_;
  };

 private:
  Storage* storage_;
};
