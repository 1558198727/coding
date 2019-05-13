#include <iostream>
#include <vector>

using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0 ){
            return 0;
        }
        int i = 0,j = nums.size()-1;
        int mid = (i+j)>>1;
        while(i <= j){
            if(nums[j] < target){
                //debug(j)
                for(int k = j+1;k < nums.size();k++){
                    if(nums[k] > target){
                        return k;
                    }
                }
                return nums.size();
            }else if(nums[mid] < target){
                i = mid+1;
            }else if( nums[mid] > target){
                j = mid - 1;
            }else{
                return mid;
            }
            mid = (i+j)>>1;
        }

        return i;
    }
};

int main()
{
    vector<int> nums = {1,3,4,6};
    Solution Solution1;
    cout << Solution1.searchInsert(nums,2) << endl;
    return 0;
}
