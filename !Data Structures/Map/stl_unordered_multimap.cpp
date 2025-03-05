#include <iostream>
#include <map>

using namespace std;

int main(){
  

  // Functions:

  // um.insert({key, value});       // Inserts a key-value pair if the key is not already present O(1) average, O(n) worst-case
  // um.erase(key);                 // Removes the key-value pair associated with 'key' O(1) average, O(n) worst-case
  // um.erase(iter);                // Removes the element at the iterator's position O(1)
  // um.clear();                    // Clears all elements from the unordered multimap O(n)
  // um.find(key);                  // Returns iterator to the key-value pair or um.end() if not found O(1) average, O(n) worst-case
  // um.count(key);                 // Returns the number of occurrences of 'key' O(1) average, O(n) worst-case
  // um.contains(key);              // (C++20) Returns true if the key exists O(1) average, O(n) worst-case
  // um.begin();                    // Returns an iterator to the first element O(1)
  // um.end();                      // Returns an iterator to the past-the-last element O(1)
  // um.lower_bound(key);           // Returns iterator to the first element >= key O(1) average, O(n) worst-case
  // um.upper_bound(key);           // Returns iterator to the first element > key O(1) average, O(n) worst-case
  // um.equal_range(key);           // Returns {lower_bound, upper_bound} O(1) average, O(n) worst-case
}