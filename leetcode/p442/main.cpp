#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        for(int i=0;i<nums.size();i++){
            nums[ abs(nums[i])-1 ] = -nums[ abs(nums[i])-1 ];
            if(nums[ abs(nums[i])-1 ]>0){
                ret.push_back( abs(nums[i]) );
            }
        }
        return ret;
    }
};

int main()
{
    vector<int>  nums = {4,3,2,7,8,2,3,1};
    Solution Solution1;
    vector<int> ret = Solution1.findDuplicates(nums);
    for(auto i:ret){
        cout << i << endl;
    }

    return 0;
}
