#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size()<3){
            return ret;
        }
        sort(nums.begin(),nums.end());
        if(nums[0] > 0 || nums[nums.size()-1] < 0){
            return ret;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                return ret;
            }
            int target = 0 - nums[i];
            int j=i+1;
            int k = nums.size() - 1;
            while(j<k){
                //debug(j)
                if(nums[j]+nums[k]==target){
                    ret.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k-1]){
                        k--;
                    }
                    j++;
                    k--;
                }else if(j<k && nums[j]+nums[k]<target){
                    j++;
                }else if(j<k && nums[j]+nums[k]>target){
                    k--;
                }
            }
            while(i<nums.size()-1 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>>ret = Solution1.threeSum(nums);
    for(auto i:ret){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}
