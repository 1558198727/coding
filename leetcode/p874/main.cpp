#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

struct point{
    int x;
    int y;
    point(int x,int y):x(x),y(y){}
    point(){}
    point operator + (point p){
        point ret;
        ret.x = this->x+ p.x;;
        ret.y = this->y+ p.y;
        return ret;
    }
    void operator += (point p){
        this->x+= p.x;
        this->y+= p.y;
    }
    point operator * (int p){
        return point(this->x* p,this->y*p);
    }
};
class Solution {
public:
    int dis(int x,int y){
        return x*x + y*y;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        point cur(0,0);
        point p2(5,7);
        int maxdis = 0;
        int curdir = 0;
        map<int,set<int> > row;
        map<int,set<int> > col;
        map<int,set<int> >::iterator it;
        //row[0] = {1,2,3};
        for(int i=0;i<obstacles.size();i++){
            row[ obstacles[i][0] ].insert(obstacles[i][1]);
        }
        //y轴向上，顺时针旋转，向右
        vector<point>dir = {point(0,1),point(1,0),point(0,-1),point(-1,0)};
        //最大值的位置不可能出现在一次方向上行走的途中 只可能在起点和终点，研究下距离函数的单调性
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1){
                curdir = (curdir+4+1)%4;
            }else if(commands[i]==-2){
                curdir = (curdir+4-1)%4;
            }else{
                for(int j = 0;j < commands[i];j++){
                    point nextpoint = cur + dir[curdir];
                    if( row[nextpoint.x].count(nextpoint.y) >0 ){
                        break;
                    }else{
                        cur += dir[curdir];
                    }
                }
                maxdis = max(maxdis,dis(cur.x,cur.y));
            }
        }
        return maxdis;
    }
};

int main()
{
    Solution Solution1;
    vector<int> commands={4,-1,4,-2,4};
    vector<vector<int>> obstacles={{2,4}};

    cout<<Solution1.robotSim(commands,obstacles)<<endl;
    return 0;
}
