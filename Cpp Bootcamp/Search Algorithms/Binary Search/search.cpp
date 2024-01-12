#include <iostream>

using std::cout;

int search(int array[], int min, int max, int n){
  
  if(min > max)return -1;

  int mid = (max + min) / 2;

  if(array[mid] == n)return mid;

  if(array[mid] < n) return search(array, mid + 1, max, n);
  else return search(array, min, mid - 1, n);
}

int chr_src(const char arr[], const char c, int min, int max){
  if(min > max) return -1;

  int mid = (min + max) / 2;

  if(arr[mid] == c) return mid;

  if(arr[mid] < c) return chr_src(arr, c, mid + 1, max);
  else return chr_src(arr, c, min, max - 1);
}

int no_recursion(const int arr[], const int n, int min, int max){
  int mid; 
  do{
    mid = (min + max) / 2;
    if(min > max) break;
    if(arr[mid] == n) return mid;
    
    if(n > arr[mid]) min = mid + 1;
    else max = mid - 1; 
  }while(true);

  return -1;
}

int main(){

  const int array[] = {-3,  -2, -1, 0, 1, 2, 3, 4, 5};
  const int n = sizeof(array) / sizeof(array[0]);
  
  const char arr[] = "ACEGHMNPRZ";
  const int size = sizeof(arr)/ sizeof(arr[0]);

  // cout << search(array, 0, n-1, 2);
  // cout << chr_src(arr, 'Z', 0, size - 1);
  cout << no_recursion(array, -2, 0, n - 1);

  return 0;
}