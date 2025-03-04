#include <iostream>
#include "heap.h"

using namespace std;

int main(){
  Heap<int> heap(false);
  heap.push(10);
  heap.push(12);
  heap.push(0);
  heap.push(-10);
  heap.push(4);

  while(!heap.empty()){
    cout << heap.pop() << " ";
  }
  cout << endl;
}