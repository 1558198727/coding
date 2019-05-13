#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct pos{
    int x;
    int y;
    int h;
    bool operator < (const pos& b)const{
        return this->h > b.h;
    }
    pos(int x,int y,int h):x(x),y(y),h(h){}
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue< pos > qu;
        for(int i=0;i<heightMap.size();i++){
            for(int j=0;j<heightMap[i].size();j++){
                qu.push( pos(i,j,heightMap[i][j]) );

            }
        }
        cout<<qu.top().h<<endl;
        return 0;
    }
};

int main()
{
    vector<vector<int> > heights = {
        {1,4,3,1,3,2},
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}
    };
    Solution Solution1;
    cout<<Solution1.trapRainWater(heights)<<endl;
    return 0;
}
