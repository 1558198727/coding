#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define debug(x) cout<<#x<<": "<<x<<endl;
class Solution {
public:
    void disp(vector<vector<int>> matrix){
        for(auto i:matrix){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false;
        bool col = false;
        if(matrix.size()==0){
            return;
        }
        if(matrix[0].size()==0){
            return;
        }
        for(int i=0;i<matrix.size();i++){
            if(!matrix[i][0]){
                col = true;
                break;
            }
        }
        for(int i=0;i<matrix[0].size();i++){
            if(!matrix[0][i]){
                row = true;
                break;
            }
        }

        //disp(matrix);
        for(int i=1;i<matrix.size();i++){
            for(int j = 1;j < matrix[i].size();j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }

        for(int i=1;i<matrix.size();i++){
            for(int j = 1;j < matrix[i].size();j++){
                if(!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(col){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0] = 0;
            }
        }
        if(row){
            for(int i=0;i<matrix[0].size();i++){
                matrix[0][i] = 0;
            }
        }
        //disp(matrix);
    }
};


int main()
{
    vector<vector<int>> matrix={
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    Solution Solution1;
    Solution1.setZeroes(matrix);

    return 0;
}
