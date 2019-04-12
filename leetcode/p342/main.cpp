#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        int cnt =0;
        for(int i=0;i<=31;i++){
            if( (1<<i) <= num ){
                if( (1<<i) & num ){
                   if(i%2==0){
                       cnt++;
                    }else{
                        return false;
                    }
                }

            }
        }
        if(cnt==1){
            return true;
        }
        return false;
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.isPowerOfFour(262144)<<endl;
    return 0;
}
