#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] == target - nums[i]) {
                ret.push_back(i);
                ret.push_back(j);
                return ret;
            }
        }
    }
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums;
    for(int i=5;i<11;i++)
    nums.push_back(i);
    for(int i=1;i<5;i++)
    nums.push_back(i);
    nums = Solution1.twoSum(nums,5);
    cout<<nums[0]<<" "<<nums[1]<<endl;
    return 0;
}
