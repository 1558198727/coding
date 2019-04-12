#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }else if(n<=2){
            return 1;
        }
        vector<int> dp(n+1,1);

        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
*/
class Solution {
public:
    int fib(int n) {
        long long ret[53]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170,1836311903,2971215073,4807526976,7778742049,12586269025,20365011074};
        return (int)ret[n];
    }
};

int main()
{
    //Solution Solution1;

    return 0;
}
