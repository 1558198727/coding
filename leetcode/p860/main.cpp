#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills.size()==0){
            return true;
        }
        map<int,int> bcnt;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                bcnt[bills[i] ]++;
            }else if(bills[i]==10){
                bcnt[bills[i]]++;
                if(bcnt[5]>0){
                    bcnt[5]--;
                }else{
                    return false;
                }
            }else if(bills[i]==20){
                bcnt[bills[i]]++;
                if(bcnt[10]>0 && bcnt[5]>0){
                    bcnt[5]--;
                    bcnt[10]--;
                }else if(bcnt[5]>2){
                    bcnt[5]-=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution Solution1;
    vector<int> bills = {5,5,5,5,20,20,5,5,20,5};
    cout<<Solution1.lemonadeChange(bills)<<endl;
    return 0;
}
