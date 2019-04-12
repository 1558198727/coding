#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0){
            return -1;
        }
        findre(vector<int>& nums,0,nums.size()-1);
        return 0;
    }
    int findre(vector<int>& nums,int s,int e){
        if
    }
};

int main()
{
    Solution Solution1;
    vector<int>aa={3,4,5,1,2};
    Solution1.findMin(aa);
    return 0;
}
