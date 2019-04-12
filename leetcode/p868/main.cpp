#include <iostream>

using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int binaryGap(int N) {
        int pos = 0;

        int max1 = 0;

        while( (N&1) ==0){
            pos++;
            //debug(N)
            N>>=1;
        }
        //debug(N);
        int pre = pos;
        int curr = pos;
        while(N){

            if(N&1){
                curr=pos;
                max1 = max(max1,curr-pre);
                pre = curr;
            }
            pos++;
            N>>=1;
        }
        cout<<max1<<endl;
        return max1;
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.binaryGap(8)<<endl;
    return 0;
}
