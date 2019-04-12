#include <iostream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        n = abs(n);
        int cnt = 0;
        while(n){
            n&=n-1;
            cnt++;
        }
        if(cnt==1){
            return true;
        }else{
            return false;
        }
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.isPowerOfTwo(32)<<endl;
    return 0;
}
