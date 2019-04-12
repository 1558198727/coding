#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <limits.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x==0){
            return 0;
        }
        int ret = 0;
        while(x != 0){
            int pop = x %10;
            x/= 10;
            if(ret > INT_MAX/10 || (ret==INT_MAX/10 && pop>7) )return 0;
            else if(ret < INT_MIN/10 || (ret==INT_MIN/10 && pop<-8) )return 0;
            ret = ret*10 + pop;

        }

        return ret;
    }
};

int main()
{

    Solution Solution1;
    cout<<Solution1.reverse(-12300)<<endl;
    return 0;
}
