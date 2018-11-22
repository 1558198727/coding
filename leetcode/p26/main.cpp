#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <set>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int start=0;
        for(int i=0;i<len-1;i++){
            if(nums[i] < nums[i+1]){
                nums[++start]= nums[i+1];
            }
        }

        return start+1;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums;

    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);

    cout<<Solution1.removeDuplicates(nums)<<endl;
    return 0;
}
