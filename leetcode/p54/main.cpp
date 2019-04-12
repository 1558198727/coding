#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.size()==0){
            return ret;
        }
        print(matrix,0,0,matrix[0].size()-1,matrix.size()-1,ret);
        return ret;
    }
    void print(vector<vector<int>>& matrix,int zuo,int shang,int you,int xia,vector<int>&ret){
        for(int i=zuo;i<=you;i++){
            ret.push_back(matrix[shang][i]);
            cout<<matrix[shang][i]<<" ";
        }
        if(shang==xia){
            return;
        }
        for(int i=shang+1;i<=xia;i++){
            ret.push_back(matrix[i][you]);
            cout<<matrix[i][you]<<" ";
        }
        if(zuo==you){
            return;
        }
        for(int i=you-1;i>=zuo;i--){
            ret.push_back(matrix[xia][i]);
            cout<<matrix[xia][i]<<" ";
        }
        for(int i=xia-1;i>=shang+1;i--){
            ret.push_back(matrix[i][zuo]);
            cout<<matrix[i][zuo]<<" ";
        }
        if(zuo+1 <= you-1 &&  shang+1<= xia-1){
            //cout<<endl<<"zuo+1  "<<zuo+1<<endl;
            //cout<<"you-1  "<<you-1<<endl;
            print(matrix,zuo+1, shang+1, you-1, xia-1,ret);
        }

    }
};

int main()
{
    Solution Solution1;
    vector<vector<int>> matrix;
    matrix.push_back(vector<int>{1,2,3,4});
    matrix.push_back(vector<int>{5,6,7,8});
    matrix.push_back(vector<int>{9,10,11,12});
    Solution1.spiralOrder(matrix);
    return 0;
}
