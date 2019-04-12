#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        set<int> s1(nums1.begin(),nums1.begin()+nums1.size());
        set<int> s2(nums2.begin(),nums2.begin()+nums2.size());
        for(auto i : s1){
            if(s2.count(i)==1){
                ret.push_back(i);
            }
        }
        return ret;

    }
};

int main()
{
    Solution Solution1;
    int nums1[4]={1,2,2,1};
    int nums2[2] = {2,2};
    vector<int>aa({1,2,2,1});
    vector<int>bb({2,2,});
    vector<int> ret = Solution1.intersection(aa,bb);
    for(auto i:ret){
        debug(i);
    }
    return 0;
}
