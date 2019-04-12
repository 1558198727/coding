#include <iostream>
#include <stdio.h>
#include <string>
#include <typeinfo>
#include <stack>
#include <vector>
#include <sstream>
#include <string.h>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;
typedef long long LL;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {

        if(z==0){
            return true;
        }else if(x+y<z){
            return false;
        }else{
            int gcdxy = gcd(x,y);
            if(z%gcdxy==0){
                return true;
            }else{
                return false;
            }
        }
    }
    int gcd(int a, int b){
        return b==0?a:gcd(b,a%b);
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.canMeasureWater(3,5,4)<<endl;
    return 0;
}
