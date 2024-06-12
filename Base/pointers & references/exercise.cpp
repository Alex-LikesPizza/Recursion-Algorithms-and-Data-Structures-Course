/*
Add elements to the vector
Insert an element
Remove an element
Access elements
Modify an element
Print all elements
*/

#include <iostream>

using namespace std;

int get(int* numArr, int poz);
void set(int* numArr, int poz, int value);
void add(int* numArr, size_t& size, int num);
void insert(int* numArr, size_t& size, int poz, int num);
void remove(int* numArr, size_t& size, int poz);

int main(){ 
  size_t size = 0;
  int* numArr = new int;
  add(numArr, size, 1);
  add(numArr, size, 2);
  add(numArr, size, 3);
  set(numArr, 2, 9);
  cout << get(numArr, 2) << endl;

  insert(numArr, size, 0, 6);
  insert(numArr, size, 2, 4);
  remove(numArr, size, 1);

  for(int i = 0; i < size; i++){
    cout << *(numArr + i) << " ";
  }
  cout << endl;
  return 0;
}

int get(int* numArr, int poz){
  return *(numArr + poz);
}
void set(int* numArr, int poz, int value){
  *(numArr + poz) = value;
}
void add(int* numArr, size_t& size, int num){
  size++;
  *(numArr + (size-1)) = num;
}
void insert(int* numArr, size_t& size, int poz, int num){
  size++;
  int temp = *(numArr + poz);
  int temp2 = *(numArr + poz + 1);
  *(numArr + poz) = num;

  for(int i = poz + 1; i < size; i++){
    *(numArr + i) = temp;
    temp = temp2;
    temp2 = *(numArr + i + 1);
  }

}

void remove(int* numArr, size_t& size, int poz){
  size--;
  for(int i = poz; i < size; i++){
    *(numArr + i) = *(numArr + i + 1);
  }
}