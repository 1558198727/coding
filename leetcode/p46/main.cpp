#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

/*
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
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
*/
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> >ret;
        vector<int> temp;
        findans(ret,nums,temp);
        return ret;
    }
    void findans(vector<vector<int> >&ret,vector<int>&nums,vector<int>temp){
        //debug(nums.size());
        if(nums.size()==0){
            ret.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            int tnum = nums[i];
            temp.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            findans(ret,nums,temp);
            nums.insert(nums.begin()+i,tnum);
            temp.pop_back();
        }
    }
};

void dispv2(vector<vector<int>> ret){
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
    vector<int> aa= {1,2,3};

    vector<vector<int> > ret = Solution1.permute(aa);
    dispv2(ret);
    return 0;
}
