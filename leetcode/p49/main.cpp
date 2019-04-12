#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;
/*class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<int,vector<string>> mpv;
        for(int i=0;i<strs.size();i++){
            int key = 0;
            for(int j=0;j<strs[i].size();j++){
                key |= 1<<(strs[i][j]-'a');
            }
            //debug(key);
            mpv[key].push_back(strs[i]);
        }

        map<int,vector<string>> :: iterator it;
        for(it=mpv.begin();it!=mpv.end();it++){
            ret.push_back(it->second);
        }
        return ret;
    }
};
*/

/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<string,vector<string>> mpv;
        for(int i=0;i<strs.size();i++){
            string key = strs[i];
            sort(key.begin(),key.end());
            //debug(key);
            mpv[key].push_back(strs[i]);
        }

        map<string,vector<string>> :: iterator it;
        for(it=mpv.begin();it!=mpv.end();it++){
            ret.push_back(it->second);
        }
        return ret;
    }
};
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        vector<long long> pri={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
        //debug(pri.size());
        map<long long,vector<string>> mpv;
        for(int i=0;i<strs.size();i++){
            long long key = 1;
            for(int j=0;j<strs[i].size();j++){
                key *= pri[strs[i][j]-'a'];
                key %= 10000000007;
            }
            //debug(key);
            mpv[key].push_back(strs[i]);
        }

        map<long long,vector<string>> :: iterator it;
        for(it=mpv.begin();it!=mpv.end();it++){
            ret.push_back(it->second);
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ret = Solution1.groupAnagrams(strs);
    for(auto i:ret){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
