#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ret(A.size(),0);
        //cout<<A.size()<<endl;
        int sum = 0;
        for(int i=0;i<A.size();i++){
            sum *= 2;
            sum += A[i];
            if(sum%5==0){
                ret[i] = 1;
            }else{
                ret[i] = 0;
            }
            sum %= 5;
        }
        return ret;
    }
};

int main()
{
    vector<int>A = {0,1,1,1,1,1};
    Solution Solution1;
    vector<bool> ret = Solution1.prefixesDivBy5(A);
    for(auto i:ret){
        cout << i << endl;
    }

    return 0;
}
