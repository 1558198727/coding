#include <iostream>
#include <vector>

using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()<=1){
            return;
        }
        sub_rotate(matrix,0,matrix.size()-1);
    }
    void sub_rotate(vector<vector<int>>& matrix,int s,int e){
        if(s>=e ){
            return;
        }
        //debug(s);
        //debug(e);
        vector<int> temp(e+1);
        for(int i=s;i<=e;i++){
            temp[i] = matrix[s][i];
        }
        //1
        for(int i=s;i<=e;i++){
            matrix[s][e-i+s] = matrix[i][s];
        }
        //2
        for(int i=s;i<=e;i++){
            matrix[i][s] = matrix[e][i];
        }
        //3
        for(int i=s;i<=e;i++){
            matrix[e][i] = matrix[e-i+s][e];
        }
        //4
        for(int i=s;i<=e;i++){
            matrix[i][e] = temp[i];
        }
        sub_rotate(matrix,s+1,e-1);
    }

};

int main()
{
    Solution Solution1;
    vector<vector<int>> matrix = {
                                {1,2,3,4},
                                {5,6,7,8},
                                {9,0,1,2},
                                {4,5,6,7},
                                };
    Solution1.rotate(matrix);
    for(auto i:matrix){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
