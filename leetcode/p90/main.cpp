#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> temp1;
        vector<vector<int>> temp2;
        vector<vector<int>> temp3;
        temp1.push_back({});
        if(nums.size() ==0){
            return temp1;
        }
        temp2.push_back({nums[0]});
        temp1.insert( temp1.end(),temp2.begin(),temp2.end() );
        temp3 = temp2;
        temp2.clear();
        for(int i=1;i < nums.size() ;i++){
            temp1.insert( temp1.end(),temp2.begin(),temp2.end() );
            if(nums[i] != nums[i-1]){
                for(int j=0;j<temp1.size();j++){
                    vector<int> ve = temp1[j];
                    ve.push_back(nums[i]);
                    temp2.push_back(ve);
                }
                temp1.insert( temp1.end(),temp2.begin(),temp2.end() );
                temp3 = temp2;
                temp2.clear();
            }else{
                for(int j=0;j<temp3.size();j++){
                    temp3[j].push_back(nums[i]);
                }
                temp1.insert( temp1.end(),temp3.begin(),temp3.end() );
            }
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
    vector<int> nums = {1,2,3,3};
    vector<vector<int>> ret = Solution1.subsetsWithDup(nums);
    disp(ret);
    return 0;
}
