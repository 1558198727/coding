#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string>vs;
        map<char,int> pcnt;
        map<char,string> ps;
        for(int i=0;i<str.size();){
            int j=i;
            j = str.find(" ",j);
            //cout<<j<<endl;
            if(j>0){
                vs.push_back(str.substr(i,j-i));
                i = j+1;
            }else{
                vs.push_back(str.substr(i,str.size()-i));
                break;
            }
        }

        if(pattern.size()!=vs.size()){
            return false;
        }
        set<char> paset;
        set<string> strset;
        for(auto i: pattern)
        paset.insert(i);
        for(auto i: vs)
        strset.insert(i);
        if(paset.size()!=strset.size()){
            return false;
        }
        for(int i=0;i<pattern.size();i++){
            if(pcnt[pattern[i]]==0){
                pcnt[pattern[i]]++;
                ps[pattern[i]] = vs[i];
            }else{
                //cout<<"ps[pattern[i]] "<<ps[pattern[i]]<<" "<<ps[pattern[i]].size()<<endl;
                //cout<<"vs[i] "<<vs[i]<<" "<<vs[i].size()<<endl;
                if( ps[pattern[i]] == vs[i]){
                    //cout<<"1111"<<endl;
                }else{
                    //cout<<"00000"<<endl;
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
    cout<<Solution1.wordPattern("abba","dddd dddd dddd dddd")<<endl;
    return 0;
}
