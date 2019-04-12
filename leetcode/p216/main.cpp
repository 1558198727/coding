#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> temp;
        find_ret(ret,temp,k,n);
        return ret;

    }

    void find_ret(vector<vector<int>>& ret,vector<int> &temp,int k, int n){

                cout<<"k "<<k<<endl;
                cout<<"n "<<n<<endl;
                for(auto i : temp){
                    cout<<i<<" ";
                }
                cout<<endl;
        if(k==1){
            if(n>=1 && n<=9){
                temp.push_back(n);
                ret.push_back(temp);
                temp.clear();
            }
        }else{
            for(int i=1;i<10;i++){
                temp.push_back(i);

                find_ret(ret,temp,k-1,n-i);
                temp.clear();
            }

        }
    }
};

int main()
{
    Solution Solution1;

    vector<vector<int>> ret;
    ret = Solution1.combinationSum3(3,7);
    /*
    for(int i = 0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return 0;
}
