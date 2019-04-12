#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int jin = 1;
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]+jin>=10){
                digits[i] = (digits[i]+jin)%10;

            }else{
                digits[i] = digits[i]+jin;
                jin = 0;
            }
        }
        if(jin)
        digits.insert(digits.begin(),1);
        return digits;
    }
};

int main()
{
    Solution Solution1;
    int a[3] ={1,2,3};
    vector<int> aa (a,a+3);
    vector<int> ret = Solution1.plusOne(aa);
    for(auto i:ret){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
