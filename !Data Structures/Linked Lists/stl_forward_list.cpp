#include <iostream>
#include <forward_list>

using namespace std;

int main() {

  forward_list<int> fl;

  // Functions: 
  
  // fl.push_front(value);    // Adds 'value' to the front of the forward list O(1)
  // fl.pop_front();          // Removes the first element O(1)
  // fl.clear();              // Clears all elements O(n)
  // fl.insert_after(iter, value); // Inserts 'value' after the specified iterator O(1)
  // fl.erase_after(iter);    // Removes the element after the specified iterator O(1)
  // fl.begin();              // Returns an iterator to the first element O(1)
  // fl.end();                // Returns an iterator to the past-the-last element O(1)
  // fl.size();               // Returns the number of elements O(n)
  // fl.empty();              // Returns true if the forward list is empty O(1)
  // fl.front();              // Returns the first element O(1)
  // fl.reverse();            // Reverses the order of the elements O(n)
}
