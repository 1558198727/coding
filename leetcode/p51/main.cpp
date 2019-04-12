#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;

        string str = "";
        for(int i=0;i<n;i++)
            str += ".";

        vector<int>a(n,-1);
        vector<vector<int> > ve;
        fang(ve,a,0);
        //cout<<tem[0][0];
        for(int i=0;i<ve.size();i++){
            vector<string> tem(n,str);
            for(int j=0;j<ve[0].size();j++){
                tem[j][ve[i][j]] = 'Q';
            }
            ret.push_back(tem);
            //cout<<endl;
        }
        return ret;
    }
    bool can(vector<int> &arr,int row,int col ){
        for(int i=0;i<row;i++){
            if(arr[i]==col){
                return false;
            }
        }
        for(int i=0;i<row;i++){
            //cout<<"ssss"<<endl;
            if(abs(row - i) == abs (col-arr[i])){
                //cout<<"aaaa"<<endl;
                return false;
            }
        }
        return true;
    }
    void fang(vector<vector<int> > &ve,vector<int>&arr,int cur){
        //cout<<"======"<<" "<<cur<<endl;
        if(cur == arr.size()){
            //cout<<"2222"<<cur<<" "<<arr.size()<<endl;
            ve.push_back(arr);
        }
        for(int i=0;i<arr.size();i++){
            //cout<<"111 "<<i<<endl;
            if(can(arr,cur,i)){
                arr[cur] = i;
                //cout<<"333 "<<i<<endl;
                fang(ve,arr,cur+1);

            }
        }

    }
};

int main()
{
    Solution Solution1;
    for (auto i :Solution1.solveNQueens(4)){
        for(auto j:i){
            cout<<j<<endl;
        }
        cout<<endl;
    }
    return 0;
}
