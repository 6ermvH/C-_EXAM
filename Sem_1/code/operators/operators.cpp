#include <iostream>
#include <cassert>
#include <string>

class Integer {
public:
  Integer(int num) : num_(num) {}
  Integer(const std::string& num) : num_(std::stoi(num)) {}
  Integer(const Integer& num) = default;
  Integer& operator= (const Integer& num) {
    num_ = num.num_;
    return *this;
  }

  const int get() const {
    return num_;
  }

  Integer& operator++ () { // Prefix ++
    ++num_;
    return *this;
  }

  const Integer operator++ (int) { // Postfix ++
    Integer tmp = *this;
    ++(*this);
    return tmp;
  }

  const Integer operator- () const { // Unary minus
    Integer tmp = *this;
    tmp.num_ *= -1;
    return tmp;
  }

  const Integer operator+ (const Integer& num) {
    Integer result(num_ + num.num_);
    return result;
  }

  friend const Integer operator- (const Integer& n1, const Integer& n2);

private:
  int num_;
};

const Integer operator- (const Integer& n1, const Integer& n2) {
  Integer result(n1.num_ - n2.num_);
  return result;
}

int main() {

  {
    Integer a(5);
    assert(a.get() == 5);
    assert((++a).get() == 6);
    assert((a++).get() == 6);
    assert(a.get() == 7);
  }

  {
    Integer a(5);
    assert((-a).get() == -5);
  }

  {
    assert((Integer(5) + Integer(5)).get() == 10); // not friend
    assert((Integer(5) + 5).get() == 10);

    /*assert((5 + Integer(5)).get() == 10);*/
    /*ошибка: no match for «operator+» (operand types are «int» and «Integer»)*/
    /*   71 |     assert((5 + Integer(5)).get() == 10);*/

    assert((5 - Integer(5)).get() == 0); // friend
    assert((Integer(5) - 5).get() == 0);
  }

}
