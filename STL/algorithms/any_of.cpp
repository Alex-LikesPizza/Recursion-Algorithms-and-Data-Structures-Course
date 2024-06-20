#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main(){
  std::vector<int> vec {0, 1, 1, 3, 4, 5, 2, 3, 1};

  bool areAnyOdd = std::any_of(vec.begin(), vec.end(), [](int x){ return x%2 != 0;});

  std::cout << std::boolalpha << areAnyOdd << std::endl;
  return 0;
}