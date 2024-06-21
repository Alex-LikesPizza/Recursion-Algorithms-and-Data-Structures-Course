#include <iostream>
#include <set>

using namespace std;

int main(){
  multiset<int> ms {1, 2, 5, 3, 2, 4, 1}; // ms = {1, 1, 2, 2, 3, 4, 5}

  ms.size(); // 7

  ms.insert(1); 
  ms.insert(6); 
  ms.emplace(7); 
  ms.count(5); 
  ms.erase(8); 
  auto it = ms.find(4); 

  ms.clear(); 
  ms.empty(); 
  return 0;
}