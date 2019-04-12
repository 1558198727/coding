#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef map<int,int>mp;
class Solution {
public:
    static bool cmp(pair<int,int>a, pair<int,int>b){
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        mp mp1;
        vector<int>ret;
        for(int i=0;i<nums.size();i++){
            mp1[nums[i]]++;
        }
        vector<pair<int,int> > vp1(mp1.begin(),mp1.end());
        sort(vp1.begin(),vp1.end(),cmp);
        for(int i=0;i<k;i++){
            ret.push_back(vp1[i].first);
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    int a[6] = {1,1,1,2,2,3};
    vector<int>aa(a,a+6);
    vector<int> ret = Solution1.topKFrequent(aa,2);
    for(auto i: ret){
        cout<<i<<endl;
    }
    return 0;
}
