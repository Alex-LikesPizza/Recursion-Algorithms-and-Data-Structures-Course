#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int main(){
  queue<int, deque<int>> q;

  q.push(1); // pushes element to back
  q.pop(); // removes element from front
  q.front();
  q.back();
  q.empty(); // bool
  q.size();
}