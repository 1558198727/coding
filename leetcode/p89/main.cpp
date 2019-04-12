#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        for(int i = 0; i < 1<<n; ++i)
            ret.push_back(i ^ (i>>1));
        return ret;
    }
};
int main()
{
    Solution Solution1;
    for(auto i :Solution1.grayCode(2)){
        cout<<i<<endl;
    }
    return 0;
}
