#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int> >& positions) {
        vector<int> ret;
        int poslen = positions.size();
        int height = 0;
        vector<vector<int> > all;
        for(int i=0;i<poslen;i++){
            vector<int> one = {positions[i].first,positions[i].first+positions[i].second-1,positions[i].second};
            height = max(height,getCurHeight(one,all));
            ret.push_back(height);
        }
        return ret;
    }

    int getCurHeight(vector<int> & one,vector<vector<int> > & all){
        int left = one[0];
        int right = one[1];
        int maxh = 0;
        for(auto i : all){
            if(i[0]>right || i[1]<left){
                continue;
            }
            maxh = max(maxh,i[2]);
        }
        one[2]+=maxh;
        all.push_back(one);
        return one[2];
    }
};
int main()
{
    Solution Solution1;
    typedef pair<int ,int>block;
    vector<block> example;
    int a[3][2] = {{1, 2}, {2, 3}, {6, 1}};
    for(int i=0;i<3;i++){
        block block1(a[i][0],a[i][1]);
        example.push_back(block1);
    }
    vector<int>ret = Solution1.fallingSquares(example);
    for(auto i:ret){
        cout<<i<<" ";
    }
    return 0;
}
