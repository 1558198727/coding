#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }else if(nums.size()==1){
            return 1;
        }
        vector<int>dp(nums.size(),1);
        int ret = 1;
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ret = max(ret,dp[i]);
            //debug(dp[i]);
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int>nums = {10,9,2,5,3,7,101,18};
    cout <<  Solution1.lengthOfLIS(nums) << endl;
    return 0;
}
