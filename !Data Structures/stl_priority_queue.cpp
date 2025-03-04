#include <iostream>
#include <vector>
#include <queue> // for std::priority_queue
#include <functional> // for std::less, std::greater...
#include <string>

using namespace std;

bool min_heap_string(const string& left, const string& right){
  return left > right;
}

template <typename T>
class CompareVectorSizes{
  operator() (const vector<T>& left, const vector<T>& right){
    return left.size() < right.size();
  }
};

int main(){
  priority_queue<int> pq; // default max priority queue

  // Operations:

  // pq.push(value); // pushes value into queue
  // pq.pop(); // removes element on top
  // pq.top(); // returns element on top
  // pq.size(); // returns size of queue
  // pq.empty(); // returns a boolean of empty check
  pq.push(1);
  pq.push(2); 
  pq.push(5); 
  pq.push(-1); 
  pq.push(0); // [5, 2, 1, 0, -1]
  while(!pq.empty()){
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl;
  
  // Custom priority queues:
  // Method 1 - using function objects(predicates): 

  priority_queue<int, vector<int>, greater<int>> pq1; // min heap;
  /*
  std::less(<)
  std::greater(>)
  std::less_equal(<=)
  std::greater_equal(>=)
  */
  
  // Method 2 - using lambda functions / simple functions
  auto min_heap = [](int& left, int& right){
    return left > right;
  };
  priority_queue<int, vector<int>, decltype(min_heap)> pq2(min_heap);

  // Method 3 - using classes
  priority_queue<vector<int>, vector<vector<int>>, CompareVectorSizes<int>> pq3;

}