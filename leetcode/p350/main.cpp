#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.begin()+ nums1.size());
        sort(nums2.begin(),nums2.begin()+ nums2.size());
        int p1 = 0;
        int p2 = 0;
        vector<int> ret;
        while(p1 < nums1.size() && p2 < nums2.size()){
            while(p1 < nums1.size() && p2 < nums2.size() && nums1[p1] < nums2[p2] ){
                p1++;
                //debug(p1);
            }
            while(p1 < nums1.size() && p2 < nums2.size() && nums1[p1] > nums2[p2]){
                p2++;
                //debug(p2);
            }
            if(p1 < nums1.size() && p2 < nums2.size() && nums1[p1]==nums2[p2]){
                ret.push_back(nums1[p1]);
                p1++;
                p2++;
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int>aa = {7,2,2,4,7,0,3,4,5};
    vector<int>bb = {3,9,8,6,1,9};
    vector<int> ret = Solution1.intersect(aa,bb);
    for(auto i:ret){
        debug(i);
    }
    return 0;
}
