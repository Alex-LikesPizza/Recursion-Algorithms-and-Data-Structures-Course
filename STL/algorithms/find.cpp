#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  std::vector<int> people {0, 1, 2, 3, 4, 5};

  auto it = find(std::begin(people), std::end(people), 4); // returns the first instance of the element 4, vec.end() if not found
  // find compares using the operator==, so it can be used with custom classes as long as it has operator== oveloaded
  if(it == people.end()) std::cout << "Person 4 not found" << std::endl;
  else std::cout << "Person 4 found" << std::endl;
  
}