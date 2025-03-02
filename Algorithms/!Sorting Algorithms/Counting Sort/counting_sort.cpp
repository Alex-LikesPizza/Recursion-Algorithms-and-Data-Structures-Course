#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> counting_sort(vector<int> arr){
  vector<int> count_arr;
  for(int val : arr){
    if(val >= count_arr.size()) count_arr.resize(val * 2);
    count_arr.at(val)++;
  }
  vector<int> end_arr(count_arr.size()); int acc {};
  for(int i = 0; i < count_arr.size(); i++){
    acc+= count_arr.at(i);
    end_arr.at(i) = acc;
  }
  vector<int> start_arr = {0}; start_arr.insert(start_arr.end(), end_arr.begin(), end_arr.end() - 1);

  
  vector<int> sorted_arr(arr.size());
  for(int val : arr){
    int& index = start_arr.at(val);
    sorted_arr.at(index) = val;
    index++;
  }

  return sorted_arr;
}

int main(){

  ifstream fin("file.in");
  ofstream fout("file.out");
  
  vector<int> arr;

  int t;
  while (fin >> t) arr.push_back(t);

  arr = counting_sort(arr);

  for(int val : arr) cout << val << " ";

  fin.close();
  fout.close();

  return 0;
}