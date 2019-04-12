////  离散化数组，然后并查集找环
//////.CSL的魔法
//////数组之间的大数对小数，小数对大数
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define debug(x) cout<<#x<<": "<<x<<endl;
LL POW(LL x,LL n){
    LL ans = 1;
    while(n){
        if(n&1){
            ans *= x;
        }
        x = x*x;
        n = n>>1;
    }
    return ans;

}
int main()
{
    cout<<POW(2,10)<<endl;
   return 0;
}
