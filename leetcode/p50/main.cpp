#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans =1.0;
        long long nn = (long long)n;
        if(nn<0){
            x = 1/x;
            nn =  -nn;
        }
        while(nn){
            if(nn&1){
                ans*=x;
            }
            x=x*x;
            nn=nn>>1;
        }
        return ans;
    }
};
int main()
{
    Solution Solution1;
    cout<<Solution1.myPow(2,-2);
    return 0;
}
