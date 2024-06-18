#include <iostream>

using namespace std;

class Base{
  public:
    virtual void displayClassName() const {cout << "Base class" << endl;}
    virtual ~Base(){};
};
class Child : public Base{
  public:
    virtual void displayClassName() const override final {cout << "Child class" << endl;}
    virtual ~Child(){};
};
class ChildChild final : public Child{
  public:
      // Runtime error: Overriding final function
    // virtual void displayClassName() const override {cout << "ChildChild class" << endl;}; 
};
// class ChildChildChild : public ChildChild{}; Error: Can't inherit final class

int main(){

}