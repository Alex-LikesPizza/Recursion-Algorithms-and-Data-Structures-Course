#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
struct Item{
  string name;
  T value;

  Item(string name, T value) : name(name), value(value){};
};

int main(){
  Item car1("Tesla", 69000);
  Item cart("Grocery", vector<string>());
  cart.value.push_back("Apples");
  cart.value.push_back("Burger");
  cart.value.push_back("C++ Advanced course");
}