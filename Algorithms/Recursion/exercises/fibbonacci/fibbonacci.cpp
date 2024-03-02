#include <iostream>

using std::cout;

// 0 1 1 2 3 5 8 13 20 34
// f(i) = f(i - 1) + f(i - 2)
int fib(int i){
  if(i == 1) return 0;
  if(i == 2) return 1;

  return fib(i - 1) + fib(i - 2);
}

int fib_tail(int i, int a = 0, int b = 1){
  if(i == 1) return a;
  if(i == 2) return b;


  return fib_tail(i - 1, b, a + b);

}

int main(){

  cout<<fib_tail(5);

  return 0;
}