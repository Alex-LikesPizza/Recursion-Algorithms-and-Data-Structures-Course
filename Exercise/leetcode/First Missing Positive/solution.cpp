#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>::iterator n = nums.begin();
        while(n != nums.end() && *n <= 0) n++;
        int i = 1;
        while(n != nums.end() && *n == i){
            if(n+1 != nums.end() && *n == *(n+1)) n++;
            else{
                n++; i++;
            }

        }
        return i;
    }
};