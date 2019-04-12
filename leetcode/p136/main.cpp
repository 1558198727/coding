#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int ret = nums[0];
        for(int i=1;i < nums.size();i++){
            ret ^= nums[i];
        }
        return ret;
    }
};
int main()
{
    Solution Solution1;
    int a[3]={2,2,1};
    vector<int> ve(a,a+3);
    cout<<Solution1.singleNumber(ve);
    return 0;
}
