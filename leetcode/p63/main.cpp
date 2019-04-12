#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0){
            return 0;
        }
        if(obstacleGrid.size()==1){
            for(int i=0;i<obstacleGrid[0].size();i++){
                if(obstacleGrid[0][i]==1){
                    return 0;
                }
            }
            return 1;
        }else if(obstacleGrid[0].size()==1){
            for(int i=0;i<obstacleGrid.size();i++){
                if(obstacleGrid[i][0]==1){
                    return 0;
                }
            }
            return 1;

        }
        return zhong(0,0,obstacleGrid);
    }
    int zhong(int a,int b,vector<vector<int>>& obstacleGrid){
        int ret = 0;
        if(obstacleGrid[a][b]){
            return 0;
        }
        if(a < obstacleGrid.size() -1 && b < obstacleGrid[0].size() -1){
            if(obstacleGrid[a+1][b]==0){
                ret +=zhong(a+1,b,obstacleGrid);
            }
            if(obstacleGrid[a][b+1]==0){
                ret +=zhong(a,b+1,obstacleGrid);
            }
        }else if(a < obstacleGrid.size() -1 && b == obstacleGrid[0].size() -1){
            if(obstacleGrid[a+1][b]==0){
                ret += zhong(a+1,b,obstacleGrid);
            }
        }else if(a == obstacleGrid.size() -1 && b < obstacleGrid[0].size() -1){
            if(obstacleGrid[a][b+1]==0){
                ret +=zhong(a,b+1,obstacleGrid);
            }
        }else{
            return 1;
        }
        return ret;
    }
};
*/

class Solution {
public:
    void disp( vector<vector<int>> dp){
        for(auto i : dp){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()==0){
            return 0;
        }

        vector<vector<long long> >dp(obstacleGrid.size(),vector<long long>(obstacleGrid[0].size(),0));

        dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1] = 1;

        for(int i = obstacleGrid.size()-1;i >= 0;i --){
            for(int j = obstacleGrid[0].size()-1;j >= 0;j --){
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                }else if(i==obstacleGrid.size()-1 && j<obstacleGrid[0].size()-1){
                    dp[i][j] = dp[i][j+1];
                }else if(j==obstacleGrid[0].size()-1 && i<obstacleGrid.size()-1){
                    dp[i][j] = dp[i+1][j];
                }else if(j < obstacleGrid[0].size()-1 && i < obstacleGrid.size()-1){
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                    cout<<"111 "<<dp[i][j]<<endl;
                }
            }
        }
        return (int)dp[0][0];
    }

};

int main()
{
    vector<vector<int> >temp(28,vector<int>(36,0));
    temp[1][1] = 1;
    int a[28][36] = {
                    {0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,0,0,1,0,1,1,0,1,0,0,1,0,0,0,1,0,0},
                    {0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
                    {1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1},
                    {0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
                    {0,0,1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,0},
                    {0,0,0,0,0,0,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0},
                    {1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,1,0,0,0,1},
                    {0,0,0,0,1,0,0,1,0,1,1,1,0,0,0,1,0,0,1,0,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0},
                    {0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0},
                    {1,0,1,0,1,1,0,1,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,1,0},
                    {0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,1,0,0,1,1,0,0,0,0,0,1,0,0,1,0,0,0,1},
                    {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0},
                    {1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
                    {0,1,0,0,1,0,0,0,0,0,1,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
                    {0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
                    {0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
                    {0,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},
                    {0,0,0,1,0,1,0,0,1,0,0,0,0,0,1,1,1,0,1,1,1,0,0,1,0,1,0,1,1,1,0,0,0,0,0,0},
                    {0,0,1,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
                    {1,1,0,0,0,0,1,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
                    {0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0},
                    {0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0,1,1,1,0,0,0,0,0,0,1,0,0,0,1,1,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0}
                };
    for(int i=0;i<28;i++){
        for(int j=0;j<36;j++){
            temp[i][j] = a[i][j];
        }
    }
    Solution Solution1;
    cout<<Solution1.uniquePathsWithObstacles(temp)<<endl;
    return 0;
}
