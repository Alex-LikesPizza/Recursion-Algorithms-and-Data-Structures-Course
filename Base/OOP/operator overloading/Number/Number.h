#ifndef _NUMBER_H_
#define _NUMBER_H_

#include <iostream>

class Number{
  friend Number operator+(const Number& lhs, const Number& rhs);
  friend Number operator-(const Number& lhs, const Number& rhs);
  friend Number operator*(const Number& lhs, const Number& rhs);
  friend Number operator/(const Number& lhs, const Number& rhs);
  friend std::ostream& operator<<(std::ostream& os, const Number& rhs);

private:
  long double *n;
public:
  Number round() const;
  Number ceil() const;
  Number floor() const;
  Number to_fixed(int floating_point) const;

  Number(const long double n);
  Number(const Number& source);
  Number(Number&& source);
  ~Number();

  Number& operator=(const Number& rhs);
  Number& operator+=(const Number& rhs);
  Number& operator-=(const Number& rhs);
  Number& operator*=(const Number& rhs);
  Number& operator/=(const Number& rhs);
};

#endif