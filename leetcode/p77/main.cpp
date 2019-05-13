#include <iostream>
#include <vector>
using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;
/*
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int>temp(k,0);
        int i=0;
        while(i>=0){
            temp[i]++;
            if(temp[i]>n){
                i--;
            }else if(i == k-1){
                ret.push_back(temp);
            }else{
                i++;
                temp[i] = temp[i-1];
            }
        }
        return ret;
    }
};
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> temp;
        findans(ret,temp,n,k,1);
        return ret;
    }
    void findans(vector<vector<int>> &ret,vector<int> temp,int n,int k,int start){
        if( n-start+1 < k){
            return;
        }else if(k == 0){
            ret.push_back(temp);
        }
        for(int i=start;i<=n;i++){
            temp.push_back(i);
            findans(ret,temp,n,k-1,i+1);
            temp.pop_back();
        }
    }
};

void dispv2(vector<vector<int>> ret){
    for(auto i:ret){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    Solution Solution1;
    vector<vector<int>> ret = Solution1.combine(5,3);
    dispv2(ret);
    return 0;
}
