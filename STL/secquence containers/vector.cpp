#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  vector<int> vec {1, 2, 3, 4, 5}; // vec = {1, 2, 3, 4, 5}
  vector<int> vec1 (5, 10); // vec = {10, 10, 10, 10, 10}

  vec.size(); // returns the size of the vector
  vec.capacity(); // returns the full size of the vector, including values that are not initialized
  vec.at(0);
  vec.front();
  vec.back();
  vec.push_back(6); // add 6 to the back of the vector 
  vec.pop_back(); // removes last element of the vector
  vec.emplace_back(1); // directly assigns values to object members, without copy/move semantics
  vec.empty();
  vec.swap(vec1);

  //inserting an element in the vector
  auto it = find(vec1.begin(), vec1.end(), 3); // the item after where you want the insertion
  // vec1.insert(it, 2); // insert an element
  vec1.insert(it, vec.begin(), vec.end()); // insert a sequence of elements
   

}