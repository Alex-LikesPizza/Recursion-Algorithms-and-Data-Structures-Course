#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& left, vector<int>& right, vector<int>& arr){
  vector<int>::iterator leftIt = left.begin(), rightIt = right.begin(), arrIt = arr.begin();
  while(leftIt != left.end() && rightIt != right.end()){
    if(*leftIt < *rightIt) {
      *arrIt = *leftIt;
      leftIt++;
    }
    else{
      *arrIt = *rightIt;
      rightIt++;
    }
    arrIt++;
  }
  while(leftIt != left.end()){
    *arrIt = *leftIt;
    leftIt++;
    arrIt++;
  }
  while(rightIt != right.end()){
    *arrIt = *rightIt;
    rightIt++;
    arrIt++;
  }
}
vector<int> merge_sort(vector<int> arr){
  if(arr.size() <= 1) return arr;

  int leftSize = arr.size() / 2;
  int rightSize = arr.size() - leftSize;

  vector<int> left; left.insert(left.begin(), arr.begin(), arr.end() - rightSize);
  vector<int> right; right.insert(right.begin(), arr.begin() + leftSize, arr.end());
  left = merge_sort(left);
  right = merge_sort(right);

  merge(left, right, arr);

  return arr;
}
int main(){

  ifstream fin("file.in");
  ofstream fout("file.out");
  
  vector<int> arr;

  int t;
  while (fin >> t) arr.push_back(t);

  arr = merge_sort(arr);

  for(int val : arr) cout << val << " ";

  fin.close();
  fout.close();

  return 0;
}