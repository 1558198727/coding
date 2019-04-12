#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:

    bool isIdealPermutation(vector<int>& A) {
        int max1;
        if(A.size()<=2){
            return true;
        }
        max1 = A[0];
        for(int i=2;i<A.size();i++){

            if(A[i]>max1){
                max1 = max(max1,A[i-1]);
            }else{
                return false;
            }

        }
        return true;
    }
};

int main()
{
    Solution Solution1;
    vector<int>aa = {0,2,1};
    cout<<Solution1.isIdealPermutation(aa)<<endl;
    return 0;
}
