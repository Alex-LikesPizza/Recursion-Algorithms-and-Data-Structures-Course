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
  unique_ptr<int> int_ptr = make_unique<int>(10);
  int_ptr.get(); // returns the address of the pointer
  int_ptr.reset(); // deletes the pointer, assigning it to a nullptr
  // no need to delete smart pointer

  // Test* test_ptr_raw = new Test(0);
  // delete test_ptr_raw; // Must delete manually

  unique_ptr<Test> test_ptr1 {new Test{1}};
  unique_ptr<Test> test_ptr2 = make_unique<Test>(2); // preferable
  // test_ptr2 = test_ptr1; // Error: cannot assign multiple pointers to the same object

  return 0;
}