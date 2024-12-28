#include <vector>
using namespace std;

class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>::iterator p1 = nums1.begin();
        vector<int>::iterator p2 = nums2.begin();
        const int stSize = nums1.size();
        const int ndSize = nums2.size();
        const int mgSize = stSize + ndSize;
        double max;
        if(mgSize % 2 == 1){
            for(int i = 0; i < mgSize / 2 + 1; i++){
                if(p1 == nums1.end()){
                    max = *p2;
                    p2++;
                }
                else if(p2 == nums2.end()){
                    max = *p1;
                    p1++;
                }
                else if(*p1 < *p2) {
                    max = *p1;
                    p1++;
                }
                else{
                    max = *p2;
                    p2++;
                }
            }
        }
        else{
             for(int i = 0; i < mgSize / 2; i++){
                if(p1 == nums1.end()){
                    max = *p2;
                    p2++;
                }
                else if(p2 == nums2.end()){
                    max = *p1;
                    p1++;
                }
                else if(*p1 < *p2) {
                    max = *p1;
                    p1++;
                }
                else{
                    max = *p2;
                    p2++;
                }
            }
            // add last max
            if(p1 == nums1.end()){
                max += *p2;
                p2++;
            }
            else if(p2 == nums2.end()){
                max += *p1;
                p1++;
            }
            else if(*p1 < *p2) {
                max += *p1;
                p1++;
            }
            else{
                max += *p2;
                p2++;
            }
            max/=2;
        }
        return max;
    }
};