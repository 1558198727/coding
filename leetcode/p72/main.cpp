#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void disp(vector< vector<int>> dp){
        for(auto i:dp){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    int minDistance(string word1, string word2) {
         vector< vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1));
         for(int i=0;i <= word2.size();i++){
            dp[0][i] = i;
         }
         for(int i=0;i<=word1.size();i++){
            dp[i][0] = i;
         }
         for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(i>j){
                    dp[i][j] = dp[j][j] + (j-i);
                }
                if( word1[i-1]== word2[j-1] ){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min( dp[i-1][j]+1 , min( 1+dp[i][j-1],1+dp[i-1][j-1]) );
                }
            }
         }
         //disp(dp);
         return dp[word1.size()][word2.size()];
    }
};

int main()
{
    Solution Solution1;
    cout << Solution1.minDistance("intention","execution") << endl;
    return 0;
}
