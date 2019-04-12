#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> >ret;
        sort(nums.begin(),nums.begin()+nums.size());
        do{
            for(int i=0;i<nums.size();i++){
                    cout<<nums[i]<<" ";
            }
            ret.push_back(nums);
            cout<<endl;
        }while(next_permutation(nums.begin(),nums.begin() + nums.size()));
        return ret;
    }
};

int main()
{
    Solution Solution1;
    int a[3] = {1,2,1};
    vector<int> aa(a,a+3);
    Solution1.permute(aa);
    return 0;
}
