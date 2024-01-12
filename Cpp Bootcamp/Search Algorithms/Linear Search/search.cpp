#include <iostream>

using std::cout;

int search(int array[], int n, int a){
  for(int i = 0; i < n; i++){
    if(array[i] == a)return i;
  }
  return -1;
}

int main(){

  int array[] = {0, -1, 2, 3, 1, -2, -3, 4, 5};
  int n = sizeof(array) / sizeof(array[0]);
  
  cout << search(array, n, 5);

  return 0;
}