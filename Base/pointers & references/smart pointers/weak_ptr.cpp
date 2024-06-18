#include <iostream>
#include <memory>

using namespace std;
class Test{
  private:
    int data;
  public:
    
    Test(int x) : data(x){
      cout << "Calling constructor for value " << data << endl;
    };
    Test() : Test(0){};
    ~Test(){
      cout << "Calling destructor for value " << data << endl;
    }
};

class Weak; // define class
class Strong{
  private:
    shared_ptr<Weak> strong_ptr;
  public:

    Strong(shared_ptr<Weak> ptr) : strong_ptr(ptr){};
    ~Strong(){}
};

class Weak{
  private:
    // shared_ptr<Strong> no_strong_ptr; // if shared_ptr, Strong->Weak and Weak->Strong so count never reaches 0
    weak_ptr<Strong> no_strong_ptr;
  public:

    Weak(weak_ptr<Strong> ptr) : no_strong_ptr(ptr){};
    ~Weak(){}
};

int main(){
  shared_ptr<Test> shared_ptr1 = make_shared<Test>(1);

  weak_ptr<Test> test_ptr1 {shared_ptr1};
  weak_ptr<Test> test_ptr2 = make_shared<Test>(2); // not valid. test_ptr2 is immediately destroyed.

  test_ptr2 = test_ptr1; // ok
  cout << "test_ptr pointers: " << test_ptr2.use_count() << endl; // 1. weak_ptr does not contribute toward count
  shared_ptr1.reset(); // resets shared_ptr1; test_ptr1 and test_ptr2 become expired (reset).



  return 0;
}