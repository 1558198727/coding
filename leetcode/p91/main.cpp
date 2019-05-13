#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;
//�ݹ鳬ʱ
/*
class Solution {
public:
    map<string,char> mp;
    void init(){
        mp["1"] = 'A';
        mp["2"] = 'B';
        mp["3"] = 'C';
        mp["4"] = 'D';
        mp["5"] = 'E';
        mp["6"] = 'F';
        mp["7"] = 'G';
        mp["8"] = 'H';
        mp["9"] = 'I';
        mp["10"] = 'J';
        mp["11"] = 'K';
        mp["12"] = 'L';
        mp["13"] = 'M';
        mp["14"] = 'N';
        mp["15"] = 'O';
        mp["16"] = 'P';
        mp["17"] = 'Q';
        mp["18"] = 'R';
        mp["19"] = 'S';
        mp["20"] = 'T';
        mp["21"] = 'U';
        mp["22"] = 'V';
        mp["23"] = 'W';
        mp["24"] = 'X';
        mp["25"] = 'Y';
        mp["26"] = 'Z';
    }
    void findw(string s,int& ret){
        //cout<<s<<endl;
        if(s.size()==0){
            ret++;
            return;
        }else if(s.size()==1){
            if(s[0]=='0'){
                return;
            }
            ret++;
        }else if(s.size()>=2){
            if( mp.count(s.substr(0,2))==1 ){
                findw( s.substr(2), ret);
            }
            if(s[0]!='0'){
                findw(s.substr(1), ret);
            }

        }
    }
    int numDecodings(string s) {
        init();
        int ret =0;
        findw(s,ret);
        return ret;
    }

};
*/


//dp
class Solution {
public:
    int numDecodings(string s) {

        s.insert(0,"$");
        vector<long long> dp(s.size(),0);
        if(s.size()==1){
            return 0;
        }
        dp[0]=1;
        if(s[1]=='0'){
            dp[1]=0;
        }else{
            dp[1]=1;
        }

        for(int i=2;i<dp.size();i++){
            //1010
            if(s[i]=='0'){
                if(s[i-1]=='1' || s[i-1]=='2'){
                    dp[i] = dp[i-2];
                }else{
                    dp[i]=0;
                }

            }else if(s[i]>='7'){
                if(s[i-1]=='1'){
                    dp[i] = dp[i-1] + dp[i-2];
                }else{
                    dp[i]=dp[i-1];
                }
            }else{
                if(s[i-1]=='1' ||s[i-1]=='2'){
                    dp[i] = dp[i-1] + dp[i-2];
                }else{
                    dp[i]=dp[i-1];
                }
            }
            //cout<<i<<" ";
            //debug(dp[i])
        }

        return dp[s.size()-1];
    }
};


int main()
{
    Solution Solution1;
    string s = "11";
    cout<<Solution1.numDecodings(s)<<endl;
    return 0;
}
