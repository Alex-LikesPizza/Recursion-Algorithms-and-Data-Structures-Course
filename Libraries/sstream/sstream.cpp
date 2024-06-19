#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

string get_format(string name, int age, string hobby){
  ostringstream oss;
  oss << left;
  oss << setw(10) << name << ": " << setw(3) << age << "Hobby - " << hobby << endl;
  return oss.str();
}

int main(){
  // --------- Input String Stream ----------- //
  istringstream iss("Alex 17 Programming\nLuca 8 Videogames\n");
  string name;
  int age;
  string hobby;
  while(iss >> name >> age >> hobby){
    cout << get_format(name, age, hobby);
  }
  // ---------- Output String Stream ----------- //
  ostringstream oss;
  name = "Mihai";
  age = 12;
  hobby = "Videogames";
  oss << get_format(name, age, hobby);
  cout << oss.str();
}