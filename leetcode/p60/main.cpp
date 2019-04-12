#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> ve(n);
        string ret = "";
        for(int i=0;i<n;i++){
            ve[i] = i+1;
        }
        do{
           k--;
        }while( k>0 && next_permutation( ve.begin(),ve.end()));
        for(int i=0;i<n;i++){
            ret += ve[i]+'0';
        }
        return ret;

    }
};
*/


int main()
{
    Solution Solution1;
    cout<<Solution1.getPermutation(3,3)<<endl;
    return 0;
}
