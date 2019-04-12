#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for(int i = 0;i < 32;i++){
            ret *=2;
            if(n&(1<<i) ){
               ret+=1;
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;

    cout << Solution1.reverseBits(4294967293) << endl;
    return 0;
}
