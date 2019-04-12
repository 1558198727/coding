#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<end;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp;
        set<char>s1(s.begin(),s.begin()+s.size());
        set<char>s2(t.begin(),t.begin()+t.size());
        if(s.size()!=t.size()){
            return false;
        }
        if(s1.size()!=s2.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            if(mp.count(s[i])==0){
                mp[s[i]]=t[i];
            }else{
                if(mp[s[i]]==t[i]){

                }else{
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.isIsomorphic("app","cds")<<endl;
    return 0;
}
