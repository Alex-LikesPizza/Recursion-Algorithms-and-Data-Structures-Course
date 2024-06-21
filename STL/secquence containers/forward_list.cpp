#include <iostream> 
#include <forward_list>
#include <iterator>

using namespace std;

int main(){
  forward_list<int> ls{1, 2, 3, 4, 5};

  ls.push_front(1);
  ls.pop_front();
  ls.front();
  ls.emplace_front(0);

  // ls.at(1); // Error: not allowed



  // invalid:
  // ls.push_back(1);
  // ls.pop_back();
  // ls.back();
  // ls.emplace_back(6);
  // ls.size();

  // specific functions:
  auto it = ls.begin(); // forward lists allow only forward traversal
  it++; // Front traversal
  advance(it, 2); // travel 2 elements in front
  ls.insert_after(it, 1); // constant time, inserts at poz it+1
  ls.erase_after(it); // erases the element at poz it+1. The iterator does not become invalid
  ls.emplace_after(it, 10); // inserts element at poz it+1, without constructors
  ls.resize(3); // resizes the list to contain 3 elements. All other elements are erased.
  ls.resize(10); // If the value is larger than the current size, the list will be filled with 0.
  ls.sort(); // sorts the list
}