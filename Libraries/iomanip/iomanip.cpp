#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  // -------------- Boolean Manipulators, Manipulator Settings --------------//
  // const bool tr = true;
  // const bool fs = false;
  // cout << "No boolalpha: "<< tr << " " << fs << endl; // 1 0
  // cout << boolalpha; // Flags cout setting boolalpha. All following cout output will be boolalpha
  // cout.setf(ios::boolalpha); // alternative
  // cout << "Boolalpha: "<< tr << " " << fs << endl; // true false
  // // cerr << "Cerr : unset boolalpha: "<< tr << " " << fs << endl; // 1 0; cerr was not flagged with boolalpha
  // cout << noboolalpha;
  // // cout << resetiosflags(ios::boolalpha); // sets to default (1 0)
  // // cout.unsetf(ios::boolalpha); // sets to default (1 0) (same as above)
  // cout << "Back to noboolalpha: "<< tr << " " << fs << endl; // 1 0

  // ----------------------- Int Manipulators -----------------------//
  // int num {255};
  // cout << "dec: " << dec << num << endl; // sets flag for number output to be base 10
  // cout << "oct: " << oct << num << endl; // base 8
  // cout << "hex: " << hex << num << endl; // base 16

  // cout << "showbase: "  <<  showbase << num << endl; // shows the base of current base flag (base16 == 0x)
  // cout << "uppercase: " << uppercase << num << " (does not affect letters)" << endl; // shows the base of current base flag (base16 == 0x)
  // cout << "Reset: "     << dec << nouppercase << noshowbase << num << endl; // hides base
  // cout << "showpos: "     << showpos << num << noshowpos << endl; // shows + symbol for positive numbers

  // ---------------------- Float Manipulators --------------------- //

  // double flt1 {1234567.1234};
  // double flt2 {123456789.987654321};
  // double flt3 {1.0};

  // // setprecision(x) - starting with the first digit, sets the number digits allowed to display 
  // // (ex: x = 2, 1.234 => 1.2); if not all whole digits are displayed, the number is displayed in scientific notation
  // cout << "default: "<< flt1 << endl; // default precision = 6
  // cout << endl;

  // cout << "setprecision(2):        " << setprecision(2) << flt1 << endl; // 1.2e+06
  // cout << "setprecision(11):       " << setprecision(11) << flt1 << endl; // 1234567.1234
  // cout << "setprecision(10):       " << setprecision(10) << flt2 << endl; // 123456790 (rounds the last digit)
  // cout << endl;

  // // fixed - setprecision(x) now works starting from the last digit
  // cout << "setprecision(2), fixed: " << setprecision(2) << fixed << flt1 << endl; // 1234567.12
  // cout << "setprecision(2), fixed: " << setprecision(2) << fixed << flt3 << endl; // 1234567.12
  // cout << endl;

  // cout << defaultfloat; // not fixed
  // // scientific - displays the number in a scientific format with fixed automatically applied.
  // cout << "defaultfloat:           " << setprecision(8) << flt1 << endl;
  // cout << "fixed:                  " << setprecision(8) << fixed << flt1 << endl;
  // cout << "scientific:             " << setprecision(8) << scientific << flt1 << endl;

  // cout << "scientific, showpos, uppercase: " << showpos << uppercase << flt1 << endl;
  
  // --------------------- Stream Manipulators ---------------------- //
  long nr {1234567890};
  string str {"Hello World!"};

  // setw(x) applies only to the next value. Sets an alignment value of x, and the elements are displayed starting from x index to left

  cout << "No width      : " << nr << " " << str << endl;
  cout << "setw(15)      : " << setw(15) << nr << " " << str << endl; 
  cout << "setw(15), left: " << left << setw(15) << nr << " " << str << endl; // left justifies content from left to right
  cout << "setfill('-')  : " << setfill('=') << setw(15) << nr << " " << str << endl; // fills empty spaces from setw with '='

  

  return 0;
}