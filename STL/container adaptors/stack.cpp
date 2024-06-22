#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
  stack<int, vector<int>> s;

  s.push(1);
  s.pop();
  s.top();
  s.empty(); // bool
  s.size();
}