#include <iostream>
#include <vector>

using namespace std;

class PositiveNumberExcept : public exception{

  virtual const char* what() const noexcept override{
    return "Not a positive number!";
  }
};

int main(){
  // ------------ Catching exception for std libraries --------------//
  vector<int> myVec(5);
  try{
    cout << myVec.at(100) << endl;
  }
  catch(exception& ex){ // thrown error is-a(n) exception
    cout << ex.what() << endl; // error: trying to access uninitialized element (myVec.size() == 5)
  }
  // ------------ Creating custom exception class -------------//
  int a = -1;
  try{
    if(a <= 0) throw PositiveNumberExcept();
    cout << "A is a positive number and equal to " << a << endl;
  }
  catch(exception& ex){ // PositiveNumberExcept is-a(n) exception
    cout << ex.what() << endl;
  }

}