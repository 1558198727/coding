#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int flag = 0;
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<bool> isVisited(nums.size(),	false);
        vector<vector<int> > ret;
        vector<int> curr;
        if(nums.size() == 0){
            return ret;
        }
        items(nums,curr,ret,isVisited);

        return ret;
    }

//递归思路
//对数组进行深度优先遍历，其中
    void items(vector<int>& nums,vector<int>& curr,vector<vector<int> > &ret,vector<bool>isVisited){
        if(curr.size() == nums.size() ){
            ret.push_back(curr);

            return;
        }
        else{
            for(int i=0 ; i<nums.size() ;i++){
                if(isVisited[i] == false){
                    isVisited[i] = true;
                    curr.push_back(nums[i]);
cout<<flag++<<endl;
                    items(nums,curr,ret,isVisited);
                    isVisited[i] = false;
                    curr.pop_back();

                }
            }
        }
    }

};
/*
//调用next_permutation找到比当前序列大的排列，所有我们需要对当前的序列进行排列
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int> curr;
        if(nums.size() == 0){
            return ret;
        }
        sort(nums.begin(), nums.end());
        int* array = new int [nums.size()];
        for(int i=0;i<nums.size();i++){
                array[i] =nums[i];
        }

        do
        {
            for(int i=0;i<nums.size();i++){
                curr.push_back(array[i]);
            }
            ret.push_back(curr);
            curr.clear();
        }
        while ( next_permutation(array,array+nums.size()) );
        return ret;
    }

};

*/
int main()
{
    Solution a;
    vector<int> nums;

    int array[3] = {0,-1,1};

    nums.insert(nums.begin(), array, array+3);

    vector<vector<int> >vec = a.permute(nums);
//cout<<vec.size()<<endl;
    for(int i = 0;i<vec.size();i++){
        for(int j=0;j<vec[0].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
