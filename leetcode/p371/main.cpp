#include <iostream>
using namespace std;


class Solution {
public:
    int getSum(int a, int b) {
        int ret = a^b;
        int carry = ((a & b)<<1);
        while(carry){
            a = ret;
            ret ^= carry;
            carry = ((a & carry)<<1);
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.getSum(-1,1)<<endl;
    return 0;
}
