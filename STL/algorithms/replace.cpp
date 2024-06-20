#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  std::vector<int> vec {0, 1, 0, 3, 0, 5, 0, 7, 0, 9};


  std::replace(std::begin(vec), std::end(vec), 0, 100); // counts the number of even numbers from the vector
  std::for_each(std::begin(vec), std::end(vec), [](int x){std::cout << x << " ";});
  // std::replace_it replaces if lambda function returns true
  return 0;
}