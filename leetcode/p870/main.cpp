#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    static bool cmp1(pair<int,int> a,pair<int,int> b){
        return a.second < b.second;
    }
    static bool cmp2(pair<int,int> a,pair<int,int> b){
        return a.first < b.first;
    }
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> ret;
        vector<pair<int,int>>vepos;
        for(int i=0;i<B.size();i++){
            pair<int,int> bpos(i,B[i]);
            vepos.push_back(bpos);
        }
        sort(vepos.begin(),vepos.end(),cmp1);
        vector<pair<int,int>>vepos2;
        for(int i=0;i<vepos.size();i++){
            pair<int,int> apos(vepos[i].first,A[i]);
            vepos2.push_back(apos);
        }
        sort(vepos2.begin(),vepos2.end(),cmp2);
        for(int i=0;i<vepos2.size();i++){
            A[i] = vepos2[i].second;
        }
        return A;
    }
};

int main()
{
    Solution Solution1;
    vector<int> A = {2,7,11,15};
    vector<int> B = {1,10,4,11};
    vector<int> ret = Solution1.advantageCount(A,B);
    for(auto i:ret){
        cout<<i<<" ";
    }
    return 0;
}
