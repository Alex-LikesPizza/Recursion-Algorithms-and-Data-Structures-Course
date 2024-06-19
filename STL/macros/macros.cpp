#include <iostream>
#include <string>

#define MAX(a, b) ((a > b)? a : b) // WARNING: macros are deprecated
// instead of defining same code functionality for multiple data types, macros allow us to create a generic operation

using namespace std;

int main(){
  cout << MAX(10, 20) << endl; // int
  cout << MAX(4.2, 3.3) << endl; // float
  cout << MAX('a', 'c') << endl; // char
  cout << MAX(string("ABC"), string("ABD")); // string
}