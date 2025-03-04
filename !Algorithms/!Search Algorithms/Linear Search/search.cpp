#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> arr, int a){
  for(int i = 0; i < arr.size(); i++){
    if(arr.at(i) == a)return i;
  }
  return -1;
}

int main(){

  vector<int> array = {0, -1, 2, 3, 1, -2, -3, 4, 5};

  cout << search(array, 5);

  return 0;
}