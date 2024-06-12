#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
  int* int_ptr {nullptr}; // initializing a pointer

  int int_var {10};
  int_ptr = &int_var;  // assigning a value
  
  *int_ptr = 20; // derefrence a pointer
  // cout << *int_ptr << endl; // 20

  //-------------------------------------------------------//

  vector<string> fruits {"apple", "banana", "tomato"};
  vector<string>* fruits_ptr = {&fruits};
  // cout << (*fruits_ptr).at(0) << endl; // apple

  // for(string fruit : *fruits_ptr){
  //   cout << fruit << " "; // apple banana tomato
  // }
  // cout << endl;

  //------------------- Dynamic Memory Allocation ------------------//
  int* number_ptr = new int;
  // cout << number_ptr; // number_ptr address
  delete number_ptr;

  size_t arraySize {10};
  // cin >> arraySize; // number of dynamically allocated space
  int* array_ptr = new int[arraySize];
  // cout << array_ptr;
  delete [] array_ptr;

  //------------------- Arrays and Pointers ------------------//
  size_t size = 10;
  int scores[] = {100, 99, 95};
  int *score_ptr {scores}; // scores returns the address of the first element of the array
                            // scores and score_ptr are now equivalent
  scores[0] = 93; // changes the first element of scores to 93
  score_ptr[0] = 92; // changes the first element of scores to 92
  cout << *scores; // 92
  
  // Subscript Notation
  scores[0]; // access the first element of the array
  scores[1]; // access the second element of the array

  // Offset Notation
  *scores; // access the first element of the array
  *(scores + 1); // access the second element of the array
}