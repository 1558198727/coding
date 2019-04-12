#include <iostream>
#include <stdio.h>
using namespace std;
class Solution {
public:
    int c(int m,int n){
        double ret = 1;
        while(n > 0){
            ret *= m;
            m--;
            ret /= n;
            n--;
        }
        printf("%.20f\n",ret);
        cout<<"11111 "<<(int)(ret+0.5)<<endl;
        return (int)(ret+0.5);

    }
    int uniquePaths(int m, int n) {
        m--;
        n--;
        m+=n;
        if(n > m/2){
            return c(m,m-n);
        }else{
            return c(m,n);
        }

    }
};
int main()
{
    Solution Solution1;
    cout<<Solution1.uniquePaths(4,6)<<endl;
    return 0;
}
