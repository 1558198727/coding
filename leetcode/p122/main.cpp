#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int ret = 0;
        for(int i = 0;i<prices.size()-1;i++){
            if(prices[i+1] > prices[i]){
                ret += prices[i+1] - prices[i];
            }
        }
        return ret;
    }
};

int main()
{

    int a[5] = {1,2,3,4,5};
    vector<int>aa(a,a);
    Solution Solution1;
    cout<<Solution1.maxProfit(aa)<<endl;
    return 0;
}
