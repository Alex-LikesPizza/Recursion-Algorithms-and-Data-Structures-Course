#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  std::vector<int> vec {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


  int nr = std::count_if(std::begin(vec), std::end(vec), [](int x){
    return x%2 == 0;
  }); // counts the number of even numbers from the vector
  std::cout << nr << std::endl;
  
}