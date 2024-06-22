#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main(){
  set<int> s {1, 5, 5, 2, 3, 1, 4}; // 1, 2, 3, 4, 5
  s.size(); // 5

  // no concept of front and back

  s.insert(1); // duplicate, is ignored
  s.insert(6); // s = {1, 2, 3, 4, 5, 6}
  s.emplace(7); // s = {1, 2, 3, 4, 5, 7}
  s.count(5); // returns 1 if in the set, 0 otherwise
  pair<set<int>::iterator, bool> isIncluded = s.insert(8); // works with emplace
  s.erase(8); // s = {1, 2, 3, 4, 5, 7}
  auto it = s.find(4); // returns it of for if exists, else s.end()

  s.clear(); // removes all elements of set
  s.empty(); // returns bool

  
  
}