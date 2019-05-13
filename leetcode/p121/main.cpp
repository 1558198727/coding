#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int ret = 0;
        int mini = prices[0];
        for(int i=1;i<prices.size();i++){
            mini = min( mini,prices[i] );
            ret = max(ret,prices[i] - mini);
        }
        return ret;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
