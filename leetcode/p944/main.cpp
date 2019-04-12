#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define debug(x)cout<<#x<<": "<<x<<endl;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if(A.size()==0){
            return 0;
        }
        int len = A[0].size();
        int ret = 0;
        for(int i=0;i<len;i++){
            //debug(ret)
            for(int j=1;j<A.size();j++){
                if(A[j][i] < A[j-1][i]){
                    //debug(A[j][i])
                    ret++;
                    break;
                }
            }
        }
        cout<<ret<<endl;
        return ret;
    }
};


int main()
{
    Solution Solution1;
    vector<string> A = {"cba", "daf", "ghi"};
    Solution1.minDeletionSize(A);
    return 0;
}
