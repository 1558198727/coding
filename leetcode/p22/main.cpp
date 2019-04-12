#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(n==0){
            return ret;
        }
        string str = "";
        make(n,n,str,ret);
        return ret;
    }
    void make(int l,int r ,string str,vector<string>& ret){
        if(l==0 && r == 0){
            ret.push_back(str);
        }
        if(l>0){
            make(l-1,r,str+"(",ret);
        }
        if(r>0){
            make(l,r-1,str+")",ret);
        }
    }
};

int main()
{
    Solution Solution1;
    vector<string> ret = Solution1.generateParenthesis(3);
    for(auto i:ret){
        cout<<i<<endl;
    }
    return 0;
}
