#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main(){
  std::vector<int> vec {0, 1, 1, 3, 4, 5, 2, 3, 1};

  bool areAllOdd = std::all_of(vec.begin(), vec.end(), [](int x){ return x%2 != 0;});
  bool areAllSmall = std::all_of(vec.begin(), vec.end(), [](int x){ return x < 10;});

  std::cout << std::boolalpha << areAllOdd << std::endl;
  std::cout << std::boolalpha << areAllSmall << std::endl;
  return 0;
}