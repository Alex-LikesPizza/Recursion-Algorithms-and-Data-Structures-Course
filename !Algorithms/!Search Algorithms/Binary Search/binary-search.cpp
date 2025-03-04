#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int binary_search(int start, int end, char target, vector<char>& arr){
  if(end < start) return -1;
  
  int middle = start + (end - start) / 2;

  if(arr.at(middle) == target) return middle;
  else if(arr.at(middle) < target) 
    return binary_search(middle + 1, end, target, arr);
  else return binary_search(start, middle - 1, target, arr);
}
int main(){

  ifstream fin("file.in");

  char target; fin >> target;

  vector<char> arr; char t;
  while(fin >> t) arr.push_back(t);

  int index = binary_search(0, arr.size() -1, target, arr);

  cout << index;
  fin.close();

  return 0;
}