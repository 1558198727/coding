#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string comm(string a,string b){
        int alen = a.size();
        int len =0 ;
        for(int i=0;i<alen;i++){
            if(a[i]==b[i]){
                len++;
            }else{
                break;
            }
        }
        return a.substr(0,len);
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        if(strs.size()<2){
            return strs[0];
        }
        string ret = strs[0];
        for(int i=1;i<strs.size();i++){
            ret = comm(ret,strs[i]);
            if(ret==""){
                break;
            }
        }
        return ret;
    }
};
int main()
{

    Solution Solution1;
    vector<string>s;
    s.push_back("flower");
    s.push_back("flow");
    s.push_back("flight");
    cout<<Solution1.longestCommonPrefix(s)<<endl;
    return 0;
}
