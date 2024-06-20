#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main(){
  std::string greeting {"hello world!"};

  std::transform(greeting.begin(), greeting.end(), greeting.begin(), toupper);

  std::cout << greeting;
  
  return 0;
}