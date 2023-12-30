#include <iostream>

using namespace std;

int factorial(int i){
  if(i == 0) return 1;
  // - head recursion
  return i * factorial(i - 1); ;

}

int tail_factorial(int i, int acc = 1){

  if(i == 0) return acc;

  return tail_factorial(i - 1, acc * i);
}

int main(){
  cout << factorial(10);

  return 0;
}