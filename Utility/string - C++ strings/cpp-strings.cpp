#include <iostream>

// must include string library
#include <string> 

using namespace std;

int main(){
// ----- Initialising ----- //
  string s1; // Empty
  string s2 {"Alex"}; // Alex
  string s3 = "Alex"; // Equivalent to s2
  string s4 {s2}; // Equivalent to s2
  string s6 {"Alexandru", 3}; // Ale (first 3 characters)
  string s7 {"Alexandru", 4, 5}; // andru (form index 4, next 5 characters)
  string s8 (5, 'A'); // AAAAA (initialises string of size 5 filled with char 'A', just like vector)

// ----- Operations ------ //
  s1 = s2; // Assignment 
  s1 = s1 + s2; // Concatenation (watch out for concatenation of 2 string-literals(cstrings), which are invalid ["he"+"lo"])
  bool isEqual = (s1 == s2); // Compare: ==, !=, >, >=, <, <=
  bool isGreater = (s1 > s2); //...

// ----- Accessing characters at index i -----//
  s3[3] = 'c'; // no bounds checking
  s3.at(3) = 'c'; // with bounds checking

// ----- Reading ----- //
  string readString;
  // cin >> s1; // only accepts to first white space
  // getline(cin, readString); // read until newline
  getline(cin, readString, '!'); // read until first '!'
  cout << readString;
  



// For info on string methods consult Libraries -> string

  return 0;
}