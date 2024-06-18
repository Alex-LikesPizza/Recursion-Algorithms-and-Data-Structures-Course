#include <iostream>
#include <cstring>
using namespace std;

class CharArray {
  friend bool operator==(const CharArray& lhs, const CharArray& rhs); // friending non-memeber function opeartors
  friend CharArray operator-(const CharArray& lhs);
  friend CharArray operator+(const CharArray& lhs, const CharArray& rhs);
  friend ostream& operator<<(ostream& os, const CharArray& rhs);
  friend istream& operator<<(istream& in, CharArray& rhs);
private:
  char* str;
public:
  CharArray();
  CharArray(const char* s);
  CharArray(const CharArray& source);
  CharArray(CharArray&& source);
  ~CharArray();
  void display() const;
  int get_length() const;
  const char* get_str() const;

  CharArray &operator=(const CharArray& rhs); // member-function operator overloading
  CharArray &operator=(CharArray&& rhs);
  // Examples
  // CharArray operator-(); // negate operator (unary) 
  // CharArray operator+(const CharArray& rhs); // addition operator (binary)
  // CharArray operator++(); // pre-increment (unary)
  // CharArray operator++(int); // post-increment (unary)
  // CharArray operator--(int); // post-decrement (unary)
  // CharArray& operator+=(const CharArray& rhs); // addition assignment operator (binary)
};

CharArray::CharArray(){
  str = new char[1];
  *str = '\0';
}
CharArray::CharArray(const char* s){
  if(s == nullptr){
    str = new char[1];
    *str = '\0';
    return;
  }
  str = new char[strlen(s) + 1];
  strcpy(str, s);
}
CharArray::CharArray(const CharArray& source){
  str = new char[strlen(source.str) + 1];
  strcpy(str, source.str);
}
CharArray::CharArray(CharArray&& source) : str{source.str}{
  source.str = nullptr;
}
CharArray::~CharArray(){
  delete [] str;
}
void CharArray::display() const{
  cout << str << ": " << get_length() << endl;
}
int CharArray::get_length() const{
  return strlen(str);
}
const char* CharArray::get_str() const {
  return str;
}

CharArray& CharArray::operator=(const CharArray& rhs){
  cout << "copy assignment" << endl;
  if(this == &rhs)
    return *this;
  delete[] str;

  str = new char[strlen(rhs.str) + 1];
  strcpy(str, rhs.str);
  return *this;
}
CharArray& CharArray::operator=(CharArray&& rhs){
  cout << "move assignment" << endl;
  if(this == &rhs)
    return *this;
  
  delete [] str;

  str = rhs.str;
  rhs.str = nullptr;

  return *this;
}

// Equality
bool operator==(const CharArray& lhs, const CharArray& rhs){ // not a member function
  return strcmp(lhs.str, rhs.str);
}

// Make Lowercase
CharArray operator-(const CharArray& obj){
  char *buff = new char[strlen(obj.str) + 1];
  strcpy(buff, obj.str);
  for(size_t i = 0; i < strlen(buff); i++){
    buff[i] = tolower(buff[i]);
  }

  CharArray temp {buff};
  delete [] buff;
  return temp;
}

// Concatenation
CharArray operator+(const CharArray& lhs, const CharArray& rhs){
  char* buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
  strcpy(buff, lhs.str);
  strcat(buff, rhs.str);
  CharArray temp {buff};
  delete [] buff;
  return temp;
}
ostream& operator<<(ostream& os, const CharArray& rhs){
  os << rhs.str;
  return os;
}
istream& operator<<(istream& in, CharArray& rhs){
  char* buff = new char[1000];
  in >> buff;
  rhs = CharArray{buff};
  delete [] buff;

  return in;
}

int main(){
  // CharArray empty;
  // CharArray larry("Larry");
  // CharArray stooge {larry};

  // empty = larry;
  // empty.display();
  // empty = "Hello world";
  // empty.display();

  CharArray chr1 = "Hello World";
  CharArray chr2 = "!";
  (chr1 + chr2).display();

  CharArray chr3 = -chr1;
  cout << chr3 << endl;

  cout << boolalpha;
  cout << (chr1 == chr3) << endl;
  cout << noboolalpha;
  cout << (chr2 == chr3) << endl;
  
  return 0;
}