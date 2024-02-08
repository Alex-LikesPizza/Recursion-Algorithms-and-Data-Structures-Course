#include <iostream>

using namespace std;

int main(){

  int a = 10;
  int b = 4;

  double c_inted = a/b;
  double c = static_cast<double>(a) / b;

  cout << "Inted: " << c_inted << endl;
  cout << "Double: " << c << endl;

  return 0;
}