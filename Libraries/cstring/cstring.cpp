#include <iostream>
#include <cstring>

using namespace std;

int main(){
// For info on cstrings (string literals) consult Utility -> C-style strings
  char firstName[] = "Alexandru";
  char lastName[] = "Solomon";
  char fullName[100] {};

  char temp[] = "Hello World!";

// cstring length
  size_t tempLen = strlen(temp);
  cout << "strlen(str) - Returns str length: " << tempLen << endl;

// assign value to cstring 
  strcpy(fullName, firstName);
  cout << "strcpy(str1, str2) - Copies str2 into str1 (str1 = str2): " << fullName << endl;

// concatenate 2 cstrings
  strcat(fullName, " ");
  strcat(fullName, lastName);
  cout << "strcat(str1, str2) - Concatenates str2 into str1 (str1 += str2)" << fullName << endl;

// compare 2 cstrings
  char comp1[] = "hello";
  char comp2[] = "hi";
  int compVal = strcmp(comp1, comp2);
  /* Returns a positive number if comp1 > comp2
     Returns 0 if comp1 == comp2
     Returns a negative number if comp1 < comp2 */
  cout << "strcmp(str1, str2) - Compares str1 and str2: " << compVal;

  return 0;
}