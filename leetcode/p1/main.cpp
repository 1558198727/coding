#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
/* ±©Á¦ O(n*n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == target - nums[i]) {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
};
*/

//ÅÅÐò O(nlog(n))
/*
class Solution {
public:
    static bool cmp(pair<int ,int> a,pair<int ,int> b){
        return a.second < b.second;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector< pair<int ,int> > ve;
        for(int i=0;i<nums.size();i++){
            pair<int ,int> pa(i,nums[i]);
            ve.push_back(pa);
        }
        sort(ve.begin(),ve.begin() + ve.size(),cmp);
        int i=0, j=nums.size()-1;
        vector<int> ret;
        while(i<j){
            if(ve[i].second + ve[j].second > target){
                j--;
            }else if(ve[i].second + ve[j].second < target){
                i++;
            }else{
                ret.push_back(ve[i].first);
                ret.push_back(ve[j].first);
                return ret;
            }
        }
        return ret;
    }
};*/

// ¹þÏ£ map O(nlog(n))
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        vector<int> ret;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i+1;
        }
        for(int i=0;i<nums.size();i++){
            if( mp[ target-nums[i] ] > 0 &&  mp[ target-nums[i] ]-1!=i ){
                ret.push_back(i);
                ret.push_back(mp[ target - nums[i] ]-1);
                return ret;
            }
        }
        return ret;
    }
};
*/

// ¹þÏ£ unordered_map O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int> ret;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i+1;
        }
        for(int i=0;i<nums.size();i++){
            if( mp[ target-nums[i] ] > 0 &&  mp[ target-nums[i] ]-1!=i ){
                ret.push_back(i);
                ret.push_back(mp[ target - nums[i] ]-1);
                return ret;
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> nums = {2,7,11,15};
    vector<int> ret = Solution1.twoSum(nums,9);
    for(auto i:ret){
        cout<<i<<endl;
    }
    return 0;
}
