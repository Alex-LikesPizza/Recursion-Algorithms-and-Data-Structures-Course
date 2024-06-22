#include <iostream>
#include <queue>

using namespace std;

int main(){
  priority_queue<int> pq;
  for(int i: {1, 1, 2, 6,5, 10, 9, 100})
    pq.push(i);
  int s = pq.size();
  for(int i = 0; i < s; i++){
      cout << pq.top() << " ";
      pq.pop();
  }
}