#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        sub(4,"",s,ret);
        return ret;
    }
    int str_int(string s){
        stringstream ss;
        ss<<s;
        int ret;
        ss>>ret;
        return ret;
    }
    void sub(int restNum,string curr,string s,vector<string> &ret){
        if(restNum==1){

            if(s.size()>0 && str_int(s)<=255 && str_int(s)>=0){
                if(s.size()>1 && s[0]=='0'){
                    return;
                }
                curr += s;
                ret.push_back(curr);
            }
            return;
        }
        if(s[0]=='0'){
            sub(restNum-1,curr+"0"+".",s.substr(1),ret);
        }else{

            for(int i=1;i<=3;i++){
                if(s.size()<i){
                    return;
                }
                string fr = s.substr(0,i);
                int fr_int  = str_int(fr);
                if(fr_int >=0 && fr_int<=255){
                    sub(restNum-1,curr+fr+".",s.substr(i),ret);
                }
            }

        }
    }
};


int main()
{
    Solution Solution1;
    vector<string> ret = Solution1.restoreIpAddresses("0000");
    for(auto i:ret){
        cout<<i<<endl;
    }
    return 0;
}
