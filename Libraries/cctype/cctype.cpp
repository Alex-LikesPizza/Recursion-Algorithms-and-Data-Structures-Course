#include <iostream>
#include <cctype>

using namespace std;

int main(){
  char c = 'A';
  bool alpha = isalpha(c);
  bool digit = isdigit(c);
  bool alnum = isalnum(c);
  bool lower = islower(c);
  bool upper = isupper(c);
  bool punct = ispunct(c);
  bool space = isspace(c);
  bool print = isprint(c);

  cout << "isalpha(c) - True if is a letter               : " << boolalpha << alpha << endl;
  cout << "isdigit(c) - True if is a digit                : " << boolalpha << digit << endl;
  cout << "isalnum(c) - True if is a letter or a digit    : " << boolalpha << alnum << endl;
  cout << "islower(c) - True if is a letter and lowercase : " << boolalpha << lower << endl;
  cout << "isupper(c) - True if is a letter and uppercase : " << boolalpha << upper << endl;
  cout << "ispunct(c) - True if is a punctuation character: " << boolalpha << punct << endl;
  cout << "isspace(c) - True if is a white space          : " << boolalpha << space << endl;
  cout << "isprint(c) - True if is a printable character  : " << boolalpha << print << endl;

  cout << "------------------------------------------------------" << endl;

  char ctolower = tolower(c);
  char ctoupper = toupper(c);

  cout << "toupper(c) - Returns the lowercase of c: " << ctolower << endl; 
  cout << "toupper(c) - Returns the uppercase of c: " << ctoupper << endl;

  return 0;
}