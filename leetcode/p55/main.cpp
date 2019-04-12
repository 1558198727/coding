#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int right = 0;
        for(int i=0;i<=right;i++){
            if(right>=nums.size()-1){
                return true;
            }
            right = max(i+nums[i],right);
        }
        return false;
    }
};

int main()
{
    int a[5] = {3,2,1,0,4};
    vector<int> aa(a,a+5);
    Solution Solution1;
    cout<<Solution1.canJump(aa)<<endl;
    return 0;
}
