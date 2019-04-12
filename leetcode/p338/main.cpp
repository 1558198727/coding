#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
    int cal(int num){
        int cnt = 0;
        while(num){
            num&=num-1;
            cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int num) {
        vector<int>ret;
        for(int i=0;i<=num;i++){
            ret.push_back(cal(i));
        }
        return ret;
    }
};
*/
class Solution {
public:

    vector<int> countBits(int num) {
        vector<int>ret;
        for(int i=0;i<=num;i++){
            ret.push_back(__builtin_popcount(i));
        }
        return ret;
    }
};


int main()
{
    Solution Solution1;
    Solution1.countBits(11257);
    return 0;
}
