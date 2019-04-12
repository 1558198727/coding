#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;
/*
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ret;
        if(s.size()<=10){
            return ret;
        }
        map<string,int>mp;
        for(int i=0;i<=s.size()-10;i++){
            mp[s.substr(i,10)]++;
        }
        map<string,int> :: iterator it;
        for(it=mp.begin();it != mp.end();it++){
            if(it->second>1){
                ret.push_back(it->first);
            }
        }
        return ret;
    }
};
*/

//”√Œª‘ÀÀ„
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ret;
        if(s.size()<=10){
            return ret;
        }
        map<int,int> atgc;
        atgc['A'-'A']=0;
        atgc['T'-'A']=1;
        atgc['G'-'A']=2;
        atgc['C'-'A']=3;
        map<int,int> bcnt;
        vector<int> bits(s.size()-9,0);
        for(int i=0;i<=s.size()-10;i++){
            for(int j=i;j<i+10;j++){
               bits[i]<<=2;
               bits[i] |= atgc[ s[j]-'A'];
            }
            if(++bcnt[ bits[i]]==2){
                ret.push_back(s.substr(i,10));
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    string s = "AAAAAAAAAAA";
    vector<string> ret = Solution1.findRepeatedDnaSequences(s);
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
