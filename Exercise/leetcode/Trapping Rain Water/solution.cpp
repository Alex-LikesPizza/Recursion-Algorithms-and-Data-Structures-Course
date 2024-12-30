#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int lTopIndex = 0;
  int rTopIndex = 0;
  int area = 0;
  int trap(vector<int> height){
    // getting graph tops
    for(int i = 0; i < height.size(); i++){
      if(height.at(lTopIndex) < height.at(i)){
        lTopIndex = i;
      }
    }
    for(int i = height.size() - 1; i >= 0; i--){
      if(height.at(rTopIndex) < height.at(i)){
        rTopIndex = i;
      }
    }
    // calculating area: left, right, middle
    int prevMaxTop = 0;
    for(int i = 0; i < lTopIndex; i++){
      int currentTop = height.at(i);
      if(prevMaxTop <= currentTop) prevMaxTop = currentTop;
      else area += prevMaxTop - currentTop;
    }
    prevMaxTop = 0;
    for(int i = height.size() - 1; i > rTopIndex; i--){
      int currentTop = height.at(i);
      if(prevMaxTop <= currentTop) prevMaxTop = currentTop;
      else area += prevMaxTop - currentTop;
    }
    prevMaxTop = 0;
    for(int i = lTopIndex; i < rTopIndex; i++){
      int currentTop = height.at(i);
      if(prevMaxTop <= currentTop) prevMaxTop = currentTop;
      else area += prevMaxTop - currentTop;
    }
    return area;
  }
};

int main(){
  Solution s;
  cout << s.trap({0,2,1,3,2,4,0,4, 2, 3}) << endl;
}