#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=val){
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};

int main()
{

    int a[8] = {0,1,2,2,3,0,4,2};
    vector<int> nums(a,a+8);
    Solution Solution1;
    cout<<Solution1.removeElement(nums,2);
    return 0;
}

