#include <iostream>
#include <unordered_set>

using namespace std;

int main(){

  unordered_multiset<int> us {0, 2, 1, 5, 2}; // 1 2 2 5 0 (no specific sorting)
  for(int i: us){
    cout << i << " ";
  }
  return 0;
}