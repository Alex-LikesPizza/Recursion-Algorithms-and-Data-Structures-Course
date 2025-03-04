#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// void quickSort(vector<int>& arr, int start, int end){
//   if(end <= start) return;
//   int i = start - 1;

//   for(int j = start; j < end; j++){
//     if(arr[j] < arr[end]){
//       swap(arr[++i], arr[j]);
//     }
//   }
//   swap(arr[++i], arr[end]);

//   quickSort(arr, start, i - 1);
//   quickSort(arr, i + 1, end);
// };

vector<int> quick_sort(vector<int> arr){
  if(arr.size() <= 1) return arr;

  int pivot = arr.size() - 1;
  int i = -1;

  for(int j = 0; j < pivot; j++){
    if(arr.at(j) < arr.at(pivot)){
      i++;
      swap(arr.at(i), arr.at(j));
    }
  }
  i++;
  swap(arr.at(i), arr.at(pivot));

  vector<int> arr1; arr1.insert(arr1.begin(), arr.begin(), arr.begin() + i);
  vector<int> arr2; arr2.insert(arr2.begin(), arr.begin() + i + 1, arr.end());
  arr1 = quick_sort(arr1);
  arr2 = quick_sort(arr2);
  copy(arr1.begin(), arr1.end(), arr.begin());
  copy(arr2.begin(), arr2.end(), arr.begin() + i + 1);
  return arr;
}


int main(){

  ifstream fin("file.in");
  ofstream fout("file.out");
  
  vector<int> arr;

  int t;
  while (fin >> t) arr.push_back(t);

  arr = quick_sort(arr);

  for(int val : arr) cout << val << " ";

  fin.close();
  fout.close();

  return 0;
}