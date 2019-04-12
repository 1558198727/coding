#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n){
            n&=n-1;
            cnt++;
        }
        return cnt;
    }

};

int main()
{
    Solution Solution1;
    cout<<Solution1.hammingWeight(0b11111111111111111111111111111101)<<endl;
    return 0;
}
