#include <iostream>
#include <deque>

using namespace std;

int main(){

  deque<int> d = {1, 2, 3, 4, 5};

  // Functions

  // d.push_back(value);   // Adds 'value' to the end of the deque O(1)
  // d.push_front(value);  // Adds 'value' to the front of the deque O(1)
  // d.pop_back();         // Removes the last element O(1)
  // d.pop_front();        // Removes the first element O(1)
  // d.clear();            // Clears all elements from the deque O(n)
  // d.insert(iter, value); // Inserts 'value' at the specified position O(n)
  // d.erase(iter);         // Removes the element at the specified iterator position O(n)
  // d.begin();            // Returns an iterator to the first element O(1)
  // d.end();              // Returns an iterator to the past-the-last element O(1)
  // d.size();             // Returns the number of elements in the deque O(1)
  // d.empty();            // Returns true if the deque is empty O(1)
  // d.at(index);          // Returns the element at the specified index O(1)
  // d.front();            // Returns the first element O(1)
  // d.back();             // Returns the last element O(1)
  // d.resize(new_size);   // Resizes deque to contain new_size elements O(n)
}