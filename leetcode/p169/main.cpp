#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
            if(mp[i]>nums.size()/2){
                return i;
            }
        }
        return 0;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {3,2,3};
    cout<<Solution1.majorityElement(nums)<<endl;
    return 0;
}
