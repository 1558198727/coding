#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int cnt = 0;
        int curr = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                cnt++;
                if(cnt>=2){
                    ;
                }else{
                    nums[curr++] = nums[i];
                }
            }else{
                nums[curr++] = nums[i];
                cnt = 0;
            }
        }
        return curr;
    }
};

int main()
{
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    Solution Solution1;
    cout<<Solution1.removeDuplicates(nums)<<endl;
    for(auto i:nums){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
