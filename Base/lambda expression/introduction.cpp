#include <iostream>
#include <functional>

using namespace std;

int main(){

  auto l_printHello = [](){
    cout << "Hello" << endl;
  }; l_printHello();

  auto l_printX = [](int x){
    cout << x << endl;
  }; l_printX(2);
  
  auto l_sum1 = [] (int x, int y) -> int {return x + y;};
  auto l_sum2 = [] (int x, int y) {return x + y;};
  cout << l_sum1(1, 2) << " " << l_sum2(1, 2) << endl;

  auto l_div = [] (auto x, auto y) {return x / y;};
  cout << l_div(5, 2) << " " << l_div(5.0, 2) << endl;

  auto l_execFunc = [] (function<void()> func) {
    func();
  }; 
  l_execFunc(l_printHello);
  l_execFunc([](){ cout << "World!" << endl;});
  
  int x = 100;
  auto l_capture_non_mutable = [x] () {
    // x += 100; // Error: non-mutable
    cout << x << endl;
  };
  auto l_capture_mutable = [x] () mutable {
    x+= 100; // change applied to lambda scope. Keeps value for future calls
    cout << x << endl;
  };
  auto l_capture_ref = [&x] () {
    x+= 100; // change applied to outside scope
    cout << x << endl;
  };
  l_capture_non_mutable();
  l_capture_mutable();
  l_capture_mutable();
  l_capture_ref();
  
  int y {20};
  auto l_capture_all_by_value = [=] () {
    cout << y << endl;
  };
  auto l_capture_all_by_reference = [&] () { 
    y += 20;
    cout << y << endl;
  };
  // auto l_capture_all_by_this = [this] () { // As class member  only, captures by reference
  //   cout << y << endl;
  // };
  return 0;
}