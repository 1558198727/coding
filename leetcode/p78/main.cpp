#include <iostream>
#include <vector>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> temp1;
        vector<vector<int>> temp2;
        temp1.push_back({});
        //debug(temp1.size());
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<temp1.size();j++){
                vector<int> ve = temp1[j];
                temp2.push_back(ve);
                ve.push_back(nums[i]);
                temp2.push_back(ve);
            }
            //swap(temp1,temp2);
            temp1 = temp2;
            temp2.clear();
        }
        return temp1;
    }
};

void disp(vector<vector<int>> ret){
    for(auto i:ret){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    Solution Solution1;
    vector<int> nums = {1,2,3,4,5};
    vector<vector<int>> ret = Solution1.subsets(nums);
    disp(ret);

    return 0;
}
