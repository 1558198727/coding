#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.size()==0 || s.size()==0){
            return 0;
        }
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        int ret = 0;
        while(i<g.size() && j < s.size()){
            if(g[i]<=s[j]){
                ret++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> g = {1,2};
    vector<int> s = {1,2,3};
    cout<<Solution1.findContentChildren(g,s)<<endl;
    return 0;
}
