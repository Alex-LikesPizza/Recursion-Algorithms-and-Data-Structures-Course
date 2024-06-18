#include <iostream>

using namespace std;

class Base{
  private:
    int value = 0;

  public:
    virtual void display()const{cout << "Base class value is " << value << endl;}
    Base(int x) : value(x){};
    virtual ~Base(){};
};
class DerivedX2 : public Base{
  private:
    int double_value = 0;

  public:
    virtual void display() const override{cout << "DerivedX2 class value is " << double_value << endl;} 
    DerivedX2(int x) : Base(x), double_value(x * 2){};
    virtual ~DerivedX2(){};
};
class DerivedX4 : public Base{
  private:
    int x4_value = 0;

  public:
    virtual void display() const override{cout << "DerivedX4 class value is " << x4_value << endl;} 
    DerivedX4(int x) : Base(x), x4_value(x * 4){};
    virtual ~DerivedX4(){};
};

void print(const Base& obj){
  obj.display();
}

int main(){
  Base* p1 = new Base(1);
  Base* p2 = new DerivedX2(1);
  Base* p3 = new DerivedX4(1);

  print(*p1); // 1
  print(*p2); // 2
  print(*p3); // 4


  delete p1;
  delete p2;
  delete p3;

  return 0;
}