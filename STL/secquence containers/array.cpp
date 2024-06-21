#include <iostream>
#include <array>

using namespace std;


int main(){
   array<int, 5> arr {0, 1, 2, 3};
   array<int, 5> arr1 {0, 1, 2, 3};

  arr.size(); // returns the size of the array
  arr[0]; // returns the value at index 0
  arr.at(0); // returns the value at index 0, does bounds checking
  arr.front(); // returns the first value of the array
  arr.back(); // returns the last value of the array
  arr.fill(10); // fills the entire array with value 10
  arr.swap(arr1); // swaps values with arr1
  arr.data(); // returns the raw array address
  arr.empty(); // returns true if the arr is empty, false otherwise
}