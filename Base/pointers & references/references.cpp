#include <iostream>
#include <vector>

using namespace std;

int main(){

  // l-value references

  // A reference is a "destructured pointer"
  // aka a variable with the same address as another variable 
  int var1 = 100;
  int& var2 = var1; // var1 is an alias to var2, var1 must be a l-value
  var1 = 200; // changing the value at &var1 and at the same time &var2
  // cout << var2 << endl; // 200
  // cout << &var1 << " = " << &var2 << endl; Ex:   0x1000 = 0x1000 (shares the same address)

  vector<int> myVec {9, 1, 2, 3};
  for(int val : myVec){
    val = 0;
  }
  // myVec == {9, 1, 2, 3};
  for(int& val : myVec){
    val = 0;
  }
  // myVec == {0, 0, 0, 0}
  
  const int& const_value = 0;
  // const_value = 2; //  Error

  // r-value references
  int i = 10;
  
  int& l_ref = i;
  // int& l_ref2 = 2; // Error. Must be an l-value

  int&& r_ref = 10;
  // int&& r_ref2 = i; // Error. Must be an r-value
  
  r_ref = 3; // ok

}