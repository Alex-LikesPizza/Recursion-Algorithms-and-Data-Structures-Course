#include <iostream>
#include <vector>
#include <algorithm>

struct Functor_Square{ // creating a functor
  void operator()(int& x){
    x*= x;
  }
};
Functor_Square functor_square; // function object

void print_value(int val){ 
  std::cout << val << " ";
}

int main(){
  std::vector<int> people {0, 1, 2, 3, 4, 5};
  std::for_each(people.begin(), people.end(), functor_square); // using functor instance
  std::for_each(people.begin(), people.end(), print_value); std::cout << std::endl; // using function reference
  std::for_each(people.begin(), people.end(), [](int x) { // using lambda expression
    std::cout << "Elem: " << x << std::endl;
  });  
}