#include <iostream>
#include <string>
#include <vector>

using namespace std;

void double_value(int* value_ptr);
int* create_array(size_t size, int defaultValue = 0);
int* dangling_ptr_maker();

int main(){
  int* int_ptr {nullptr}; // initializing a pointer

  int int_var {10};
  int_ptr = &int_var;  // assigning a value

  *int_ptr = 20; // dereference a pointer
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
  // cout << *scores; // 92
  
  // Subscript Notation
  scores[0]; // access the first element of the array
  scores[1]; // access the second element of the array

  // Offset Notation
  *scores; // access the first element of the array
  *(scores + 1); // access the second element of the array

  //-------------------- Pointer Arithmetics --------------------//

  int arr[] {0, 1, 2, 3, 4, 5};
  int* arr_ptr = arr; // ptr points to first element of array (0)
  arr_ptr++; // ptr points to second element of array (1)
  arr_ptr--; // ptr points to first element of array (0)
  arr_ptr += 5; // ptr points to element indexed 5 (5)
  // cout << *arr_ptr;


  int* arr_ptr1 {&arr[1]};
  int* arr_ptr2 {&arr[2]};
  int* arr_ptr3 {&arr[1]};

  cout << (arr_ptr1 == arr_ptr2) << endl; // false
  cout << (arr_ptr1 == arr_ptr3) << endl; // true
  cout << (arr_ptr2 > arr_ptr3) << endl; // true

  //-------------- Constant Pointers ------------//

  const int* constant_data {arr};
  // *constant_data = 2; // Error
  constant_data = {arr + 1}; // ok

  int *const constant_ptr {arr};
  *constant_ptr = 2; // ok
  // constant_ptr = arr + 1; // Error

  const int* const constant_ptr_and_data {arr};
  // *constant_data = 2; // Error
  // constant_ptr = arr + 1; // Error
  
  //--------------------- Pointers in Functions ----------------------//

  int value = 10;
  int* value_ptr = &value;
  double_value(&value); // ok
  double_value(value_ptr); // ok
  // cout << value << endl; // 40

  int* heapArr = create_array(10); // create an array with a function
  delete [] heapArr;
  // -------------------- Pointer Pitfalls ---------------------//

  int* uninitialized_ptr; // pointing anywhere
  // *uninitialized_ptr = 2; 

  cout << *dangling_ptr_maker(); // dangling ptr

  int* new_ptr = new int; // if new_ptr failed to allocate memory, program will crash
  
}

int* dangling_ptr_maker(){
  int returned = 99; // local scope, memory freed on return
  int* returned_ptr = &returned;
  return returned_ptr;
}

void double_value(int* value_ptr){
  *value_ptr *= 2;
}

int* create_array(size_t size, int defaultValue){
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    *(arr + i) = defaultValue;
  }
  return arr;
}