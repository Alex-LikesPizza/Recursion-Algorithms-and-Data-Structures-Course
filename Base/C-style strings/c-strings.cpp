#include <iostream>
#include <cstring>

using namespace std;

int main(){

  // ----- Initialising ------- //
  char test1[] = "Hello!";
  // test1 has been initialised with size 7, where test1[6] is 0 or '\0'.
  char test2[10] = "Hello!";
  // test2 has been initialised with size 10, where test2[6..9] is 0.
  char test3[10];
  // test3 has been initialised with size 10, where all values are unknown(?).
  char test4[10] {};
  // test4 has been initialised with size 10, where all values are 0.

  // ----- Reading ----- //
  char name[50] {};

  // cout << "Enter name: ";
  // cin >> name;
  // cout << "cin >> name - Reads to the first white space: " << name << endl;
  cout << "Enter name: ";
  cin.getline(name, 48);
  cout << "cin.get(str, size) - Reads first 48 characters (including white space) or 'till pressing enter" << endl;
  cout << "name: " << name;
  
  // View Libraries -> cstring for c-style string functions.

  return 0;
}