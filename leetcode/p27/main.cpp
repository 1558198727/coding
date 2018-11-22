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
        if(len<1){
            return len;
        }else if(len==1){
            if(nums[0]==val)
                return 0;
            else
                return 1;
        }
        int i=0;
        int j=len - 1;

        while(i<j){
            while(nums[i]!=val && i<j){
                i++;
            }
            while(nums[j]==val && i<j){
                j--;
            }
            swap(nums[i],nums[j]);
        }

       return i;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    Solution Solution1;
    cout<<Solution1.removeElement(nums,3);
    return 0;
}

