#include <iostream>
#include <set> // !!! 

using namespace std;

int main(){
  multiset<char> letters = {'C', 'D', 'A', 'D', 'C'}; // inserts duplicates D and C

  letters.insert('E'); // adds new E element in O(log n)
  letters.erase('A'); // deletes element A in O(log n)

  for(char el : letters){
    cout << el << endl; // alphabetical order
  }

  // Functions:
  
  // s.insert(value);    // Always inserts 'value' (duplicates allowed) O(log n)
  // s.erase(value);     // Removes all occurrences of 'value' O(log n)
  // s.erase(iter);      // Removes value at the iterator's position O(log n)
  // s.clear();          // Clears all elements O(n)
  // s.find(value);      // Returns iterator to first occurrence of 'value' O(log n)
  // s.count(value);     // Returns number of occurrences O(log n)
  // s.contains(value);  // (C++20) Returns true if 'value' exists O(log n)
  // s.begin();          // Returns an iterator to the first element O(1)
  // s.end();            // Returns an iterator to the last element O(1)
  // s.lower_bound(value); // Returns iterator to the first element >= value O(log n)
  // s.upper_bound(value); // Returns iterator to the first element > value O(log n)
  // s.equal_range(value); // Returns {lower_bound, upper_bound} O(log n)
}