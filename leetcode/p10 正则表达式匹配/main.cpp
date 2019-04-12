#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size();
        int plen = p.size();


        bool ** dp = new bool*[slen + 1];
        for (int i = 0; i < slen+1; i++)
            dp[i] = new bool[plen + 1];

        for (int i = 0; i < slen+1; i++)
            for (int j = 0; j < plen+1; j++)
                dp[i][j] = false;


        dp[0][0] = true;

        for (int i = 1; i < plen; i++)
            if (p[i] == '*'&&dp[0][i - 1])
                dp[0][i + 1] = true;

        for(int i = 0 ;i < slen ; i ++){
            for(int j = 0;j < plen;j++){
                if(s[i] == p[j]){
                    dp[i+1][j+1] = dp[i][j];
                }else if(p[j]=='.'){
                    dp[i+1][j+1] = dp[i][j];

                }else if(p[j]=='*'){
                    if(p[j-1]!=s[i] && p[j-1]!='.'){
                        dp[i+1][j+1] = dp[i+1][j-1];
                    }
                    else{
                        dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
                    }
                }
            }
        }

        return dp[slen][plen] ;
    }
};

int main()
{
    Solution Solution1;
    if(Solution1.isMatch("mississippi", "mis*is*p*.")){
        cout<<"sss"<<endl;
    }else{
        cout<<"dddd"<<endl;
    }
    return 0;
}
