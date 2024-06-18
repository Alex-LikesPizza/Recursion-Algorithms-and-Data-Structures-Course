#include <iostream>

using namespace std;

class Base{
  private:
    int value = 0;
  public:
    void display()const{cout << "Base class value is " << value << endl;}
    Base(int x) : value(x){};
};
class Derived : public Base{
  private:
    int double_value = 0;
  public:
    void display()const{cout << "Derived class double value is " << double_value << endl;} 
    Derived(int x) : Base(x), double_value(x * 2){};
};

void print(const Base& obj){ // Derived type valid, Derived is-a Base
  obj.display(); // Calls only Base::display();
}

int main(){
  Base obj1{2};
  Derived obj2{5};

  obj1.display(); // Calls Base::display()
  obj2.display(); // Calls Derived::display()
  print(obj1); 
  print(obj2);

  Base* obj3 = new Derived(3);
  obj3->display(); // Calls Base::display(); Derived::display() wanted

  delete obj3;
  return 0;
}