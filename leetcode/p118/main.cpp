#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> >ret;
        for(int i=1;i<numRows+1;i++){
            vector<int>row(i);
            row[0] = row[i-1] = 1;
            for(int j=1;j<i-1;j++){
                row[j] = ret[i-2][j] + ret[i-2][j-1];
            }
            ret.push_back(row);
        }
        return ret;
    }
};
int main()
{
    Solution Solution1;
    vector<vector<int>> rt;
    rt = Solution1.generate(8);

    return 0;
}
