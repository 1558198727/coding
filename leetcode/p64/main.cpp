#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0){
            return 0;
        }
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size()));
        dp[0][0] = grid[0][0];
        for(int i=1;i<dp[0].size();i++){
            dp[0][i] = dp[0][i-1]+grid[0][i];
        }
        for(int i=1;i<dp.size();i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[i].size();j++){
                dp[i][j]= min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }

        return dp[grid.size()-1][grid[0].size()-1];
    }
};

int main()
{
    Solution Solution1;
    vector<vector<int>> grid = {{1,3,1},
                                {1,5,1},
                                {4,2,1}};
    cout<<Solution1.minPathSum(grid)<<endl;
    return 0;
}
