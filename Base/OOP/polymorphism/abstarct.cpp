#include <iostream>

using namespace std;

class I_Printable{ // creating interface
  friend ostream& operator<<(ostream& os, const I_Printable& printable);
  public: // all public
    virtual void print(ostream& os) const = 0; // only pure virtual functions
    virtual ~I_Printable(){};
};
ostream& operator<<(ostream& os, const I_Printable& printable){
  printable.print(os);
  return os;
}

class Shape: public I_Printable{ // abstract class, because it contains 1 or more pure virtual functions
  public:
    virtual void draw() = 0; // pure virtual function
    virtual ~Shape(){};
};
class Square : public Shape{ // concrete class
  public:
    virtual void draw() override{ // If not all pure virtual function are defined, class becomes abstract
      //define functionality here. 
    };
    virtual void print(ostream& os) const override{ // defining interface functionality for concrete function
      os << "Printing Square" << endl;
    };
    virtual ~Square(){};
};

int main(){
  // Shape anyShape; // Error: Shape::draw() is a pure virtual function
  Square anySquare; // ok
  Shape* virtualSquare = new Square; // ok
  cout << *virtualSquare << endl;
}