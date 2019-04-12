#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n<=1){
            return 1;
        }
        vector<int> dp(n+1,1);

        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.climbStairs(3)<<endl;
    return 0;
}
