#include <iostream>
#include <string>

using namespace std;

template<typename T>
T t_max(T t1, T t2){
  return t1 > t2? t1 : t2;
}

struct Number{
  double n;
  Number(double n) : n(n){};
};
bool operator>(const Number& lhs, const Number& rhs){ // must define operator> used in template func
  return lhs.n > rhs.n;
}
bool operator<(const Number& lhs, const Number& rhs){
  return lhs.n < rhs.n;
}
ostream& operator<<(ostream& os, const Number& src){
  os << src.n;
  return os;
}
int main(){
  // --------- Templates with defined operator classes --------- //
  // cout << t_max(1, 2) << endl;
  // cout << t_max(1.0, 0.6) << endl;
  // cout << t_max('c', 'b') << endl;
  // cout << t_max<string>("abc", "bac") << endl;

  // --------- Templates with custom classes --------- //
  Number nr1(1);
  Number nr2(2);
  cout << t_max(nr1, nr2) << endl; // must define all operators used in the template
  return 0;
}