#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
  unordered_set<char> letters = {'C', 'D', 'A', 'D', 'C'}; // does not insert duplicates D and C

  letters.insert('E'); // adds new E element in O(log n)
  letters.erase('A'); // deletes element A in O(log n)

  for(char el : letters){
    cout << el << endl; // no ordering
  }
  // Functions:
  
  // s.insert(value);    // Inserts 'value' if not already present O(log n)
  // s.erase(value);     // Removes 'value' if it exists O(log n)
  // s.clear();          // Removes all elements O(n)
  // s.find(value);      // Returns an iterator to 'value' or s.end() if not found O(log n)
  // s.count(value);     // Returns 1 if 'value' exists, otherwise 0 O(log n)
  // s.contains(value);  // (C++20) Returns true if 'value' exists O(log n)
  // s.begin();          // Returns an iterator to the first element O(1)
  // s.end();            // Returns an iterator to the last element O(1)
}