#include <iostream> 
#include <deque> // double ended queue

using namespace std;

int main(){
  deque<int> que{1, 2, 3, 4, 5};

  que.at(1);
  que.push_back(1);
  que.pop_back();
  que.push_front(1);
  que.pop_front();
  que.front();
  que.back();
  que.emplace_back(6);
  que.emplace_front(0);
}