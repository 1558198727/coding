#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int min1 = nums[0];
        for(int i=0;i<nums.size();i++){
            min1 = min(min1,nums[i]);
        }
        return min1;
    }
};

int main()
{
    Solution Solution1;
    vector<int>aa={3,4,5,1,2};
    Solution1.findMin(aa);
    return 0;
}
