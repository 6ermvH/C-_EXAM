#include "shared_ptr.hpp"

#include <algorithm>
#include <iostream>

shared_ptr::shared_ptr(Matrix* obj) {
  if (obj) {
    storage_ = new Storage(obj);
  } else {
    storage_ = nullptr;
  }
}

shared_ptr::shared_ptr(const shared_ptr& other) : storage_(other.storage_) {
  if (storage_) {
    storage_->incr();
  }
}

shared_ptr& shared_ptr::operator=(shared_ptr other) {
  std::swap(storage_, other.storage_);
  return *this;
}

shared_ptr::~shared_ptr() {
  if (!storage_) {
    return;
  }
  storage_->decr();
  if (storage_->getCounter() == 0) {
    delete storage_;
  }
}

Matrix* shared_ptr::ptr() const {
  if (!storage_) {
    return nullptr;
  } else {
    return storage_->getObject();
  }
}

bool shared_ptr::isNull() const { return (storage_ == nullptr); }

void shared_ptr::reset(Matrix* obj) {
  this->~shared_ptr();
  if (obj) {
    storage_ = new Storage(obj);
  } else {
    storage_ = nullptr;
  }
}

Matrix* shared_ptr::operator->() const { return storage_->getObject(); }

Matrix& shared_ptr::operator*() const { return *(storage_->getObject()); }
