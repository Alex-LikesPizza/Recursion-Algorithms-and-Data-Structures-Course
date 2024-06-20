#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  std::vector<int> vec {0, 1, 1, 3, 4, 5, 2, 3, 1};


  int nr = std::count(std::begin(vec), std::end(vec), 1); // counts the number of elements "1", from the vector
  std::cout << nr << std::endl;
  
}