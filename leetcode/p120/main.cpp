#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0 || triangle[0].size()==0){
            return 0;
        }else if(triangle.size()==1){
            return triangle[0][0];
        }
        for(int i=1;i<triangle.size();i++){
            triangle[i][0] += triangle[i-1][0];
            for(int j=1;j<triangle[i].size()-1;j++){
                triangle[i][j] += min(triangle[i-1][j],triangle[i-1][j-1]);
            }
            triangle[i][triangle[i].size()-1] += triangle[i-1][triangle[i-1].size()-1];
        }
        int ret  = INT_MAX;
        for(int i=0;i<triangle[triangle.size()-1].size();i++){
            ret  = min(ret, triangle[triangle.size()-1][i]);
        }
        return ret;
    }
};

int main()
{
    vector< vector<int> >nums={
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };
    Solution Solution1;
    cout<<Solution1.minimumTotal(nums)<<endl;
    return 0;
}
