#include <iostream>
#include <set>

using namespace std;

int main(){
  set<char> letters = {'C', 'D', 'A', 'D', 'C'}; // does not insert duplicates D and C

  letters.insert('E'); // adds new E element in O(log n)
  letters.erase('A'); // deletes element A in O(log n)

  for(char el : letters){
    cout << el << endl; // alphabetical order
  }

  cout << "Check if element D is present: " << boolalpha << (letters.find('D') != letters.end()) << endl;
  cout << "Check if element B is present: " << boolalpha << bool(letters.count('B')) << endl;


  // Functions: 

  // s.insert(value);    // Inserts 'value' if not already present O(log n)
  // s.erase(value);     // Removes 'value' if it exists O(log n)
  // s.clear();          // Removes all elements O(n)
  // s.find(value);      // Returns an iterator to 'value' or s.end() if not found O(log n)
  // s.count(value);     // Returns 1 if 'value' exists, otherwise 0 O(log n)
  // s.contains(value);  // (C++20) Returns true if 'value' exists O(log n)
  // s.begin();          // Returns an iterator to the first element O(1)
  // s.end();            // Returns an iterator to the last element O(1)
  // s.lower_bound(value);  // Returns iterator to the first element >= value O(log n)
  // s.upper_bound(value);  // Returns iterator to the first element > value O(log n)
  // s.equal_range(value);  // Returns {lower_bound, upper_bound} O(log n)
}