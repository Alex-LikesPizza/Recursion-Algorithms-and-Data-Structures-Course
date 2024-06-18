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

int main(){
  shared_ptr<int> int_ptr = make_shared<int>(10);

  int_ptr.get(); // returns the address of the pointer
  int_ptr.reset(); // deletes the pointer, assigning it to a nullptr
  int_ptr.use_count(); // returns the number of pointers pointing to this object. 0 if nullptr

  shared_ptr<Test> test_ptr1 {new Test{1}};
  shared_ptr<Test> test_ptr2 = make_shared<Test>(2); // preferable
  test_ptr2 = test_ptr1; // ok, shared ptr count for previous test_ptr2 ref becomes 0 so the object is destroyed 
  cout << "test_ptr pointers: " << test_ptr1.use_count() << endl; // 2
  
  return 0;
}