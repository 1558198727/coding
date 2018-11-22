#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1000000000;
const int maxn = 100;


class Solution {
public:
    int target=0;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%k){
            return false;
        }
        target = sum/k;
        vector<bool> visited(nums.size(),false);
        return partitionKSubsets(nums,k,visited,0,0);
    }

    bool partitionKSubsets(vector<int>& nums,int k,vector<bool>& visited,int curSize,int start){

        if(k==1){
            return true;
        }
        if(curSize>target){
            return false;
        }
        if(curSize == target){
            return partitionKSubsets(nums,k-1,visited,0,0);
        }
        for(int i = start;i<nums.size();i++){
            if(!visited[i]){
                visited[i]= true;
                if(partitionKSubsets(nums,k,visited,curSize+nums[i],i+1)){
                    return true;
                }
                visited[i]= false;
            }
        }
        return false;
    }

};
int main()
{
    Solution Solution1;
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    cout<<Solution1.canPartitionKSubsets(nums,k)<<endl;
    return 0;
}
