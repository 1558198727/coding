#include <iostream>

using namespace std;

bool isBadVersion(int version){
    if(version<=3){
        return false;
    }else{
        return true;
    }
}
#define debug(x) cout<<#x<<": "<<x<<endl;
class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1){
            return 1;
        }
        long long i = 1;
        long long j = n;
        long long mid = (i+j)>>1;
        while(i<=j){
            //debug(i);
            //debug(j);
            //debug(mid);
            if( !isBadVersion(mid) ){//ºÃµÄ
                i = mid+1;
            }else{
                if(mid==0){
                    return 0;
                }else{
                    if( isBadVersion(mid-1) ){
                        j = mid -1;
                    }else{
                        return mid;
                    }
                }
            }
            mid = (i+j)>>1;
        }
        return mid;
    }
};

int main()
{
    Solution Solution1;
    cout<<Solution1.firstBadVersion(5)<<endl;
    return 0;
}
