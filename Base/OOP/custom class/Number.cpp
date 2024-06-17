#include <iostream>
#include <cmath>
#include "Number.h"

Number operator+(const Number& lhs, const Number& rhs){
  return *lhs.n + *rhs.n;
}
Number operator-(const Number& lhs, const Number& rhs){
  return *lhs.n - *rhs.n;
}
Number operator*(const Number& lhs, const Number& rhs){
  return *lhs.n * *rhs.n;
}
Number operator/(const Number& lhs, const Number& rhs){
  return *lhs.n / *rhs.n;
}
std::ostream& operator<<(std::ostream& os, const Number& rhs){
  os << *rhs.n;
  return os;
}
Number& Number::operator=(const Number& rhs){
  if(&rhs == this){
    return *this;
  }
  delete n;
  n = new (long double)(*rhs.n);
  return *this;
};
Number& Number::operator+=(const Number& rhs){
  *n += *rhs.n;
  return *this;
};
Number& Number::operator-=(const Number& rhs){
  *n -= *rhs.n;
  return *this;
};
Number& Number::operator*=(const Number& rhs){
  *n *= *rhs.n;
  return *this;
};
Number& Number::operator/=(const Number& rhs){
  *n /= *rhs.n;
  return *this;
};

Number Number::round() const {
  return std::round(*n);
};
Number Number::ceil() const {
  return std::ceil(*n);
};
Number Number::floor() const {
  return std::floor(*n);
};
Number Number::to_fixed(int floating_point) const {
  Number temp {*n};
  temp *= pow(10, floating_point);
  temp = temp.floor();
  temp *= pow(10, -floating_point);

  return temp;
};

Number::Number(const long double n) : n{new (long double)(n)}{};
Number::Number(const Number& source){
  n = new long double(*source.n);
};
Number::Number(Number&& source){
  delete n;
  n = source.n;
  source.n = nullptr;
};
Number::~Number(){
  delete n;
};

int main(){
  Number n{2.342};
  Number m{1.657};

  std::cout << n.to_fixed(6);
}