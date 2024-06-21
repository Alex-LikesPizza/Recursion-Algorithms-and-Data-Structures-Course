#include <iostream> 
#include <list>

using namespace std;

int main(){
  list<int> ls{1, 2, 3, 4, 5};

  ls.push_back(1);
  ls.pop_back();
  ls.push_front(1);
  ls.pop_front();
  ls.front();
  ls.back();
  ls.emplace_back(6);
  ls.emplace_front(0);

  // specific functions:
  auto cit = ls.cbegin(); advance(cit, 3);
  ls.insert(cit, 1); // constant time
  ls.erase(cit); // erases the element. The iterator becomes invalid
  ls.resize(3); // resizes the list to contain 3 elements. All other elements are erased.
  ls.resize(10); // If the value is larger than the current size, the list will be filled with 0.
  ls.sort();
  // ls.at(1); // Error: not allowed

  auto it = ls.begin(); // bidirectional lists allow both front and back traversals
  it++; // Front traversal
  it--; // Back traversal

}