#include <iostream>
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
  getline(cin, readString, '!'); // read until first '!'      ------readValue
  cout << readString;

  string str = "Hello World!";
// ----- Get string length ----- //
  int strLen = str.length();
  // cout << strLen;

// ----- Get a substring from string ----- //
  string str1 = str.substr(6); // Returns last 6 characters ("World!")
  string str2 = str.substr(0, 5); // Returns from index 0 the next 5 characters ("Hello")
  // cout << str1;

// ----- Find a substring in a string ----- //
  int strFind1 = str.find("World"); // returns the index of the first instance of "World" (6)
  int strFind2 = str.find('o', 5); // returns the index of the first instance after index 5 of 'o' (7)
  int strFind3 = str.find('X'); // returns -1 (string::npos) since there is no 'X' in the string
  // cout << strFind3;

// ----- Erase from string ----- //
  string str3 = str;
  str3.erase(11); // Erase everything after index 11 (excluding 11) ("Hello World");
  // cout << str3;
  str3.erase(0, 6); // Erase at index 0 the next 6 characters ("World")
  // cout << str3;
  str3.clear(); // Clear string ("")
  // cout << str3;

}